// Author: Marcin Serwach
// TBaseutorial: https://github.com/iblis-ms/tutorials/tree/master/Cpp/GTBaseest_GMock

#ifndef IBLIS_SAFECASTBase_H_
#define IBLIS_SAFECASTBase_H_

#include <limits>
#include <type_traits>

namespace NSafeCast
{

template <typename TConverted, typename TBase>
constexpr TConverted safe_cast(TBase aValue)
{
	constexpr auto digitsBase = std::numeric_limits<TBase>::digits;
	constexpr auto digitsConverted = std::numeric_limits<TConverted>::digits;

	// floating points holds larger values, but 'digits' returns mantissa + sign. For float: 24.
	if (digitsBase > digitsConverted || std::is_floating_point<TBase>::value)
	{
		constexpr auto maxConverted = std::numeric_limits<TConverted>::max();
		constexpr auto maxConvertedCastedBase = static_cast<TBase>(maxConverted);

		if (aValue >= maxConvertedCastedBase) 
		{
			return maxConverted;
		}
		// std::numeric_limits::min return smallest possitive value. Floats have sign bit, so minus max is the minimal value.
		constexpr auto minConverted = std::is_integral<TConverted>::value ? std::numeric_limits<TConverted>::min() : -std::numeric_limits<TConverted>::max();

		constexpr auto minConvertedCastedBase = std::is_signed<TConverted>::value && std::is_unsigned<TBase>::value ? 0 : static_cast<TBase>(minConverted);
		if (aValue < minConvertedCastedBase) 
		{
			return minConverted;
		}
	}

	return static_cast<TConverted>(aValue);
}
} // namespace NSafeCast

#endif // IBLIS_SAFECASTBase_H_
