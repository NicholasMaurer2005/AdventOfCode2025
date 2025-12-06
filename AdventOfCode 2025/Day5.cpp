#include "Days.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <cstddef>
#include <vector>
#include <charconv>
#include <format>

#include "Helper.h"
#include "SplitString.h"



void Day5Part1() noexcept
{
	struct alignas(8) Range
	{
		int begin, end;
	};

	const std::string data{ readFile("Day5.txt") };


	//find length of ranges list
	const auto splitIndex{ data.find("\n\n") };
	const std::ptrdiff_t rangesListSize{ std::count(data.begin(), data.begin() + splitIndex, '\n') + 1 }; //data ends with /0 not /n

	const SplitString rangesLines{ std::string_view(data.begin(), data.begin() + splitIndex), '\n' };
	const SplitString idsLines{ std::string_view(data.begin() + splitIndex + 2, data.end()), '\n' }; //+2 because splitIndex is the start of \n\n

	//first day with more then one heap allocation so sad
	std::vector<Range> ranges;
	ranges.resize(rangesListSize);

	std::ranges::transform(rangesLines, ranges.begin(), [](std::string_view line) {
		const std::size_t dashPos{ line.find('-') };

		Range range{};
		std::from_chars(line.data(), line.data() + dashPos, range.begin);
		std::from_chars(line.data() + dashPos + 1, line.data() + line.length(), range.end);

		return range;
		});

	std::ranges::for_each(ranges, [](Range range) {
		std::cout << std::format("{} - {}\n", range.begin, range.end);
		});
}

void Day5Part2() noexcept
{

}
