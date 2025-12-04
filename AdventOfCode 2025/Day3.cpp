#include "Days.h"

#include <iostream>
#include <algorithm>
#include <array>

#include "Helper.h"
#include "SplitString.h"



void Day3Part1() noexcept
{
	const std::string data{ readFile("Day3.txt") };
	const SplitString lines{ data, '\n' };
	
	int sum{};

	std::ranges::for_each(lines, [&sum](std::string_view line) {
		
		//this made me so happy I love c++ iterators
		const auto first{ std::max_element(line.begin(), line.end() - 1) };
		const auto second{ std::max_element(first + 1, line.end()) };

		sum += 10 * (*first - '0') + (*second - '0');
		});

	std::cout << sum << std::endl;
}

void Day3Part2() noexcept
{
	const std::string data{ readFile("Day3.txt") };
	const SplitString lines{ data, '\n' };

	std::uint64_t sum{};

	std::ranges::for_each(lines, [&sum](std::string_view line) {
		constexpr std::size_t digitCount{ 12 };

		std::array<char, digitCount> digits{};

		auto start{ line.begin() };

		for (std::size_t i{}; i < digitCount; ++i)
		{
			std::string_view nick{ start, line.end() - digitCount + i + 1 };
			const auto digit{ std::max_element(start, line.end() - digitCount + i + 1) };
			digits[i] = *digit;
			start = digit + 1;
		}

		std::uint64_t number{};
		std::from_chars(digits.data(), digits.data() + digits.size(), number);

		sum += number;
		});

	std::cout << sum << std::endl;
}