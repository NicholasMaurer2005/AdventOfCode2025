#include "Days.h"

#include "Helper.h"
#include "SplitString.h"

#include <iostream>
#include <algorithm>
#include <string_view>
#include <string>
#include <charconv>
#include <cstdint>

void Day2Part1() noexcept
{
	const std::string data{ readFile("Day2.txt") };
	const SplitString split{ data, ',' };

	std::uint64_t sum{};

	std::ranges::for_each(split, [&sum](std::string_view s) {
		const std::size_t dashPos{ s.find('-') };

		std::uint64_t first{};
		std::uint64_t second{};
		std::from_chars(s.data(), s.data() + dashPos, first);
		std::from_chars(s.data() + dashPos + 1, s.data() + s.size(), second);

		for (std::uint64_t i{ first }; i <= second; ++i)
		{
			const std::string number{ std::to_string(i) };

			if (number.length() % 2 == 0)
			{
				//experimenting with variable shadowing (name hiding)
				std::uint64_t first{};
				std::uint64_t second{};

				const std::size_t splitIndex{ number.length() / 2 };
				std::from_chars(number.data(), number.data() + splitIndex, first);
				std::from_chars(number.data() + splitIndex, number.data() + number.length(), second);

				//not branchless, msvc still generates a jne. But for the sake of my own personal 
				//challenge (and to prove a point) I will leave it.
				sum += (first == second ? i : 0);
			}
		}
		});

	std::cout << sum << std::endl;
}

static bool pattern(std::string_view stringNumber, std::size_t splitSize)
{
	for (auto it{ stringNumber.begin() + splitSize }; it < stringNumber.end(); it += splitSize)
	{
		if (!std::equal(stringNumber.begin(), stringNumber.begin() + splitSize, it))
		{
			return false;
		}
	}

	return true;
}

static bool validId(std::uint64_t number)
{
	//yeah this is not gonna be branchless
	const std::string stringNumber{ std::to_string(number) };

	for (std::size_t i{ 2 }; i <= stringNumber.length(); ++i)
	{
		//cannot divide evenly
		if (stringNumber.length() % i != 0) continue;

		std::size_t splitSize{ stringNumber.length() / i };

		if (pattern(stringNumber, splitSize))
		{
			return true;
		}
	}

	return false;
}

void Day2Part2() noexcept
{
	const std::string data{ readFile("Day2.txt") };
	const SplitString split{ data, ',' };

	std::uint64_t sum{};

	std::ranges::for_each(split, [&sum](std::string_view s) {
		const std::size_t dashPos{ s.find('-') };

		std::uint64_t first{};
		std::uint64_t second{};
		std::from_chars(s.data(), s.data() + dashPos, first);
		std::from_chars(s.data() + dashPos + 1, s.data() + s.size(), second);

		for (std::uint64_t i{ first }; i <= second; ++i)
		{
			sum += validId(i) ? i : 0;
		}
		});

	std::cout << sum << std::endl;
}
