// Author: Marcin Serwach
// Tutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTest_GMock

#ifndef IBLIS_SAFECAST_H_
#define IBLIS_SAFECAST_H_

#include <limits>
#include <type_traits>

template <typename U, typename T>
constexpr U safe_cast(T t)
{
	constexpr auto digits_t = std::numeric_limits<T>::digits;
	constexpr auto digits_u = std::numeric_limits<U>::digits;

	// floating points holds larger values, but 'digits' returns mantissa + sign. For float: 24.
	if (digits_t > digits_u || std::is_floating_point<T>::value)
	{
		constexpr auto max_u = std::numeric_limits<U>::max();
		constexpr auto max_tu = static_cast<T>(max_u);

		if (t >= max_tu) {
			return max_u;
		}
		// std::numeric_limits::min return smallest possitive value. Floats have sign bit, so minus max is the minimal value.
		constexpr auto min_u = std::is_integral<U>::value ? std::numeric_limits<U>::min() : -std::numeric_limits<U>::max();

		constexpr auto min_tu = std::is_signed<U>::value && std::is_unsigned<T>::value ? 0 : static_cast<T>(min_u);
		if (t < min_tu) {
			return min_u;
		}
	}

	return static_cast<U>(t);
}

#endif // IBLIS_SAFECAST_H_
