// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#include <utility>
#include <tuple>
#include <limits>
#include <type_traits>
#include "SafeCast.h"

#include <gtest/gtest.h>

using namespace ::testing;
using namespace ::NSafeCast;

template<typename TType>
struct SValues
{
	TType iMinBase;
	TType iMinConverted;
	TType iZero;
	TType iMaxConverted;
	TType iMaxBase;
};

template<typename TConverted, typename TBase>
using DTestValues = std::pair<SValues<TConverted>, SValues<TBase>>;


template<typename T>
constexpr T minValue() noexcept
{
	return std::is_floating_point<T>::value ? -std::numeric_limits<T>::max() : std::numeric_limits<T>::min();
}


template<typename TConverted, typename TBase>
constexpr std::enable_if<, 
	std::is_same<TConverted, TBase>::value,
	DTestValues<TConverted, TBase>
>::type createData()
{
	return std::make_pair<SValues<TConverted>, SValues<TBase>>(
		{
			minValue<TBase>(), 
			minValue<TConverted>(),
			0,
			std::numeric_limits<TConverted>::max(),
			std::numeric_limits<TBase>::max()
		},
		{
			minValue<TConverted>(), 
			minValue<TConverted>(),
			0,
			std::numeric_limits<TConverted>::max(),
			std::numeric_limits<TConverted>::max()
		});
}

template<typename TConverted, typename TBase>
constexpr std::enable_if<, 
	!std::is_same<TConverted, TBase>::value,
	DTestValues<TConverted, TBase>
>::type createData()
{
	return std::make_pair<SValues<TConverted>, SValues<TBase>>(
		{
			minValue<TBase>(), 
			minValue<TConverted>(),
			0,
			std::numeric_limits<TConverted>::max(),
			std::numeric_limits<TBase>::max()
		},
		{
			minValue<TConverted>(), 
			minValue<TConverted>(),
			0,
			std::numeric_limits<TConverted>::max(),
			std::numeric_limits<TConverted>::max()
		});
}

template<typename TPair>
class CSafeCastTest : public Test
{
public:

	using TConverted = TPair::first_type;
	using TBase = TPair::second_type;

  CSafeCastTest()
      :
        iData { createData<TConverted, TBase>() }
  {
  }

protected:
	DTestValues<TConverted, TBase> iData;
};


// Provides a list of types - it is easier to use typedef/using
typedef Types<
		// signed -> signed
		// from signed long long
		std::pair<signed long long, signed long long>,
		std::pair<signed long, signed long long>,
		std::pair<signed int, signed long long>,
		std::pair<signed short, signed long long>,
		std::pair<signed char, signed long long>,
		std::pair<long double, signed long long>,
		std::pair<double, signed long long>,
		std::pair<float, signed long long>,

		// from signed long
		std::pair<signed long long, signed long>,
		std::pair<signed long, signed long>,
		std::pair<signed int, signed long>,
		std::pair<signed short, signed long>,
		std::pair<signed char, signed long>,
		std::pair<long double, signed long>,
		std::pair<double, signed long>,
		std::pair<float, signed long>,

		// from signed int
		std::pair<signed long long, signed int>,
		std::pair<signed long, signed int>,
		std::pair<signed int, signed int>,
		std::pair<signed short, signed int>,
		std::pair<signed char, signed int>,
		std::pair<long double, signed int>,
		std::pair<double, signed int>,
		std::pair<float, signed int>,

		// from signed short
		std::pair<signed long long, signed short>,
		std::pair<signed long, signed short>,
		std::pair<signed int, signed short>,
		std::pair<signed short, signed short>,
		std::pair<signed char, signed short>,
		std::pair<long double, signed short>,
		std::pair<double, signed short>,
		std::pair<float, signed short>,

		// from signed char
		std::pair<signed long long, signed char>,
		std::pair<signed long, signed char>,
		std::pair<signed int, signed char>,
		std::pair<signed short, signed char>,
		std::pair<signed char, signed char>,
		std::pair<long double, signed char>,
		std::pair<double, signed char>,
		std::pair<float, signed char>,

		// signed -> unsigned
		// from signed long long
		std::pair<unsigned long long, signed long long>,
		std::pair<unsigned long, signed long long>,
		std::pair<unsigned int, signed long long>,
		std::pair<unsigned short, signed long long>,
		std::pair<unsigned char, signed long long>,
		std::pair<long double, signed long long>,
		std::pair<double, signed long long>,
		std::pair<float, signed long long>,

		// from signed long
		std::pair<unsigned long long, signed long>,
		std::pair<unsigned long, signed long>,
		std::pair<unsigned int, signed long>,
		std::pair<unsigned short, signed long>,
		std::pair<unsigned char, signed long>,
		std::pair<long double, signed long>,
		std::pair<double, signed long>,
		std::pair<float, signed long>,

		// from signed int
		std::pair<unsigned long long, signed int>,
		std::pair<unsigned long, signed int>,
		std::pair<unsigned int, signed int>,
		std::pair<unsigned short, signed int>,
		std::pair<unsigned char, signed int>,
		std::pair<long double, signed int>,
		std::pair<double, signed int>,
		std::pair<float, signed int>,

		// from signed short
		std::pair<unsigned long long, signed short>,
		std::pair<unsigned long, signed short>,
		std::pair<unsigned int, signed short>,
		std::pair<unsigned short, signed short>,
		std::pair<unsigned char, signed short>,
		std::pair<long double, signed short>,
		std::pair<double, signed short>,
		std::pair<float, signed short>,

		// from signed char
		std::pair<unsigned long long, signed char>,
		std::pair<unsigned long, signed char>,
		std::pair<unsigned int, signed char>,
		std::pair<unsigned short, signed char>,
		std::pair<unsigned char, signed char>,
		std::pair<long double, signed char>,
		std::pair<double, signed char>,
		std::pair<float, signed char>,

		// unsigned -> signed
		// from unsigned long long
		std::pair<signed long long, unsigned long long>,
		std::pair<signed long, unsigned long long>,
		std::pair<signed int, unsigned long long>,
		std::pair<signed short, unsigned long long>,
		std::pair<signed char, unsigned long long>,
		std::pair<long double, unsigned long long>,
		std::pair<double, unsigned long long>,
		std::pair<float, unsigned long long>,

		// from unsigned long
		std::pair<signed long long, unsigned long>,
		std::pair<signed long, unsigned long>,
		std::pair<signed int, unsigned long>,
		std::pair<signed short, unsigned long>,
		std::pair<signed char, unsigned long>,
		std::pair<long double, unsigned long>,
		std::pair<double, unsigned long>,
		std::pair<float, unsigned long>,

		// from unsigned int
		std::pair<signed long long, unsigned int>,
		std::pair<signed long, unsigned int>,
		std::pair<signed int, unsigned int>,
		std::pair<signed short, unsigned int>,
		std::pair<signed char, unsigned int>,
		std::pair<long double, unsigned int>,
		std::pair<double, unsigned int>,
		std::pair<float, unsigned int>,

		// from unsigned short
		std::pair<signed long long, unsigned short>,
		std::pair<signed long, unsigned short>,
		std::pair<signed int, unsigned short>,
		std::pair<signed short, unsigned short>,
		std::pair<signed char, unsigned short>,
		std::pair<long double, unsigned short>,
		std::pair<double, unsigned short>,
		std::pair<float, unsigned short>,

		// from unsigned char
		std::pair<signed long long, unsigned char>,
		std::pair<signed long, unsigned char>,
		std::pair<signed int, unsigned char>,
		std::pair<signed short, unsigned char>,
		std::pair<signed char, unsigned char>,
		std::pair<long double, unsigned char>,
		std::pair<double, unsigned char>,
		std::pair<float, unsigned char>,

		// unsigned -> unsigned
		// from unsigned long long
		std::pair<unsigned long long, unsigned long long>,
		std::pair<unsigned long, unsigned long long>,
		std::pair<unsigned int, unsigned long long>,
		std::pair<unsigned short, unsigned long long>,
		std::pair<unsigned char, unsigned long long>,
		std::pair<long double, unsigned long long>,
		std::pair<double, unsigned long long>,
		std::pair<float, unsigned long long>,

		// from unsigned long long
		std::pair<unsigned long long, unsigned long>,
		std::pair<unsigned long, unsigned long>,
		std::pair<unsigned int, unsigned long>,
		std::pair<unsigned short, unsigned long>,
		std::pair<unsigned char, unsigned long>,
		std::pair<long double, unsigned long>,
		std::pair<double, unsigned long>,
		std::pair<float, unsigned long>,

		// from unsigned long long
		std::pair<unsigned long long, unsigned int>,
		std::pair<unsigned long, unsigned int>,
		std::pair<unsigned int, unsigned int>,
		std::pair<unsigned short, unsigned int>,
		std::pair<unsigned char, unsigned int>,
		std::pair<long double, unsigned int>,
		std::pair<double, unsigned int>,
		std::pair<float, unsigned int>,

		// from unsigned long long
		std::pair<unsigned long long, unsigned short>,
		std::pair<unsigned long, unsigned short>,
		std::pair<unsigned int, unsigned short>,
		std::pair<unsigned short, unsigned short>,
		std::pair<unsigned char, unsigned short>,
		std::pair<long double, unsigned short>,
		std::pair<double, unsigned short>,
		std::pair<float, unsigned short>,

		// from unsigned long long
		std::pair<unsigned long long, unsigned char>,
		std::pair<unsigned long, unsigned char>,
		std::pair<unsigned int, unsigned char>,
		std::pair<unsigned short, unsigned char>,
		std::pair<unsigned char, unsigned char>,
		std::pair<long double, unsigned char>,
		std::pair<double, unsigned char>,
		std::pair<float, unsigned char>,

		// from long double
		// from unsigned long long
		std::pair<signed long long, long double>,
		std::pair<signed long, long double>,
		std::pair<signed int, long double>,
		std::pair<signed short, long double>,
		std::pair<signed char, long double>,
		std::pair<long double, long double>,
		std::pair<double, long double>,
		std::pair<float, long double>,

		// from double
		// from unsigned long long
		std::pair<signed long long, double>,
		std::pair<signed long, double>,
		std::pair<signed int, double>,
		std::pair<signed short, double>,
		std::pair<signed char, double>,
		std::pair<long double, double>,
		std::pair<double, double>,
		std::pair<float, double>,

		// from double
		// from unsigned long long
		std::pair<signed long long, float>,
		std::pair<signed long, float>,
		std::pair<signed int, float>,
		std::pair<signed short, float>,
		std::pair<signed char, float>,
		std::pair<long double, float>,
		std::pair<double, float>,
		std::pair<float, float>
	> TestingTypes;

TYPED_TEST_CASE(CSafeCastTest, TestingTypes);

TYPED_TEST(CSafeCastTest, safe_cast_test){
	const auto& base = iData.second;
	const auto& converted = iData.first;
	ASSERT_EQ(safe_cast<decltype(base.iMinBase)>(base.iMinBase), base.iMinBase);
	ASSERT_EQ(safe_cast<decltype(base.iMinConverted)>(base.iMinConverted), base.iMinConverted);
	ASSERT_EQ(safe_cast<decltype(base.iZero)>(base.iZero), base.iZero);
	ASSERT_EQ(safe_cast<decltype(base.iMaxConverted)>(base.iMaxConverted), base.iMaxConverted);
	ASSERT_EQ(safe_cast<decltype(base.iMaxBase)>(base.iMaxBase), base.iMaxBase);
}


int main(int argc, char **argv) {
	InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

#if 0

template<typename T1, typename T2>
void test_the_same_sign()
{
	T2 before = std::numeric_limits<T2>::max();
	T1 value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::max());

	before = std::numeric_limits<T1>::max();
	value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::max());

	before = 0;
	value = int_cast<T1, T2>(before);
	assert(value == 0);

	before = std::numeric_limits<T1>::min();
	value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::min());

	before = std::numeric_limits<T2>::min();
	value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::min());
}


template<typename T1, typename T2>
void test_floats()
{
	T2 before = std::numeric_limits<T2>::max();
	T1 value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::max());

	before = std::numeric_limits<T1>::max();
	value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::max());

	before = 0;
	value = int_cast<T1, T2>(before);
	assert(value == 0);

	before = -std::numeric_limits<T1>::max();
	value = int_cast<T1, T2>(before);
	assert(value == -std::numeric_limits<decltype(value)>::max());

	before = -std::numeric_limits<T2>::max();
	value = int_cast<T1, T2>(before);
	assert(value == -std::numeric_limits<decltype(value)>::max());
}



template<typename T1, typename T2>
void test_unsigned_to_signed()
{
	T2 before = std::numeric_limits<T2>::max();
	T1 value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::max());

	before = std::numeric_limits<T1>::max();
	value = int_cast<T1, T2>(before);
	assert(value == std::numeric_limits<decltype(value)>::max());

	before = 0;
	value = int_cast<T1, T2>(before);
	assert(value == 0);

	before = std::numeric_limits<T2>::min();
	value = int_cast<T1, T2>(before);
	assert(value == 0);
}


int main()
{

	test_the_same_sign<signed int, signed long>();
	test_the_same_sign<signed short, signed long>();
	test_the_same_sign<signed char, signed long>();
	test_the_same_sign<signed short, signed int>();
	test_the_same_sign<signed char, signed int>();
	test_the_same_sign<signed char, signed short>();

	test_the_same_sign<unsigned int, unsigned long>();
	test_the_same_sign<unsigned short, unsigned long>();
	test_the_same_sign<unsigned char, unsigned long>();
	test_the_same_sign<unsigned short, unsigned int>();
	test_the_same_sign<unsigned char, unsigned int>();
	test_the_same_sign<unsigned char, unsigned short>();

	test_unsigned_to_signed<signed int, unsigned long>();
	test_unsigned_to_signed<signed short, unsigned long>();
	test_unsigned_to_signed<signed char, unsigned long>();
	test_unsigned_to_signed<signed short, unsigned int>();
	test_unsigned_to_signed<signed char, unsigned int>();
	test_unsigned_to_signed<signed char, unsigned short>();

	test_the_same_sign<unsigned int, signed long>();
	test_the_same_sign<unsigned short, signed long>();
	test_the_same_sign<unsigned char, signed long>();
	test_the_same_sign<unsigned short, signed int>();
	test_the_same_sign<unsigned char, signed int>();
	test_the_same_sign<unsigned char, signed short>();

	test_the_same_sign<unsigned long, float>();
	test_the_same_sign<unsigned int, float>();
	test_the_same_sign<unsigned short, float>();
	test_the_same_sign<unsigned char, float>();


	test_unsigned_to_signed<signed long, float>();
	test_unsigned_to_signed<signed int, float>();
	test_unsigned_to_signed<signed short, float>();
	test_unsigned_to_signed<signed char, float>();

	test_the_same_sign<unsigned long, double>();
	test_the_same_sign<unsigned int, double>();
	test_the_same_sign<unsigned short, double>();
	test_the_same_sign<unsigned char, double>();

	test_unsigned_to_signed<signed long, double>();
	test_unsigned_to_signed<signed int, double>();
	test_unsigned_to_signed<signed short, double>();
	test_unsigned_to_signed<signed char, double>();


	test_the_same_sign<unsigned long, long double>();
	test_the_same_sign<unsigned int, long double>();
	test_the_same_sign<unsigned short, long double>();
	test_the_same_sign<unsigned char, long double>();

	test_unsigned_to_signed<signed long, long double>();
	test_unsigned_to_signed<signed int, long double>();
	test_unsigned_to_signed<signed short, long double>();
	test_unsigned_to_signed<signed char, long double>();

	test_floats<double, double long>();
	test_floats<float, double long>();
	test_floats<float, double>();

    return 0;
}
#endif 


