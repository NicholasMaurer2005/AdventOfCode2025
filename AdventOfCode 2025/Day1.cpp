#include "Days.h"

#include "Helper.h"
#include "SplitString.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <charconv>
#include <format>



void Day1Part1() noexcept
{
	const std::string data{ readFile("Day1.txt") };
	
	const SplitString lines{ data, '\n' };

	int dial{ 50 };
	int zeros{};

	std::ranges::for_each(lines, [&dial, &zeros](std::string_view line) {
		int number{};
		std::from_chars(line.data() + 1, line.data() + line.size(), number);

		dial += (line.front() == 'R' ? number : 100 - number);
		dial %= 100;

		zeros += dial == 0 ? 1 : 0;
		});

	std::cout << zeros << std::endl;
}

void Day1Part2() noexcept
{
	const std::string data{ readFile("Day1.txt") };

	const SplitString lines{ data, '\n' };

	int dial{ 50 };
	int zeros{};

	std::ranges::for_each(lines, [&dial, &zeros](std::string_view line) {
		int number{};
		std::from_chars(line.data() + 1, line.data() + line.size(), number);

		zeros += number / 100;
		number %= 100;

		const int dialCopy{ dial };
		dial += (line.front() == 'R' ? number : 100 - number);
		dial %= 100;

		zeros += (dial == 0) || (line.front() == 'R' && dialCopy > dial && dialCopy != 0) || (line.front() == 'L' && dialCopy < dial && dialCopy != 0);
		});

	std::cout << zeros << std::endl;
}