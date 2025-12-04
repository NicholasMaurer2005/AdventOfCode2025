#pragma once

#include <string_view>
#include <string>
#include <charconv>
#include <cmath>
#include <cstddef>



std::string readFile(std::string_view file) noexcept;



//I went and did some testing. If a number has less then 14 digits then splitting via string
//and from_chars is faster then the math way. I think this is because of how slow division, power, and log
//is mixed with sso. Once the string is large enough to heap allocate the math formula becomes about twice as fast.

//14 digits or less
template<typename T1, typename T2>
static void splitNumberString(T1 number, T2& first, T2& second) noexcept
{
	const std::string stringNumber{ std::to_string(number) };
	const std::size_t splitIndex{ stringNumber.length() / 2 };

	std::from_chars(stringNumber.data(), stringNumber.data() + splitIndex, first);
	std::from_chars(stringNumber.data() + splitIndex, stringNumber.data() + stringNumber.length(), second);
}

//more then 14 digits
template<typename T1, typename T2>
static void splitNumberMath(T1 number, T2& first, T2& second) noexcept
{
	const int digitsCount{ static_cast<int>(std::log10f(number)) + 1 };
	const int midpoint{ digitsCount / 2 };
	const std::uint64_t divisor{ static_cast<std::uint64_t>(std::pow(10, midpoint)) };

	second = static_cast<T2>(number) % divisor;
	first = static_cast<T2>(number) / divisor;
}

template<typename T1, typename T2>
static void splitNumberDynamic(T1 number, T2& first, T2& second) noexcept
{
	if (number <= 14)
	{
		splitNumberString(number, first, second);
	}
	else
	{
		splitNumberMath(number, first, second);
	}
}