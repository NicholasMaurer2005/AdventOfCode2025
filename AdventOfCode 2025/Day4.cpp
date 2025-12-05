#include "Days.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <cstddef>
#include <iterator>

#include "Helper.h"
#include "SplitString.h"





class Solution1
{
	std::string data{ readFile("Day4.txt") };
	int width{};
	int height{};

	bool test(int x, int y) const noexcept
	{
		return x >= 0 && x < width && y >= 0 && y < height && (data[y * width + x] == '@');
	}

public:

	Solution1() noexcept
	{
		//remove null terminator
		data.pop_back();
		width = static_cast<int>(std::distance(data.begin(), std::ranges::find(data, '\n'))) + 1;
		height = static_cast<int>(std::ranges::count(data, '\n') + 1);

		int count{};

		for (int y{}; y < height; ++y)
		{
			for (int x{}; x < width - 1; ++x)
			{
				int adjacentCount{};

				if (data[y * width + x] != '@')
				{
					continue;
				}

				//N
				if (test(x, y - 1)) ++adjacentCount;
				//NE
				if (test(x + 1, y - 1)) ++adjacentCount;
				//E
				if (test(x + 1, y)) ++adjacentCount;
				//SE
				if (test(x + 1, y + 1)) ++adjacentCount;
				//S
				if (test(x, y + 1)) ++adjacentCount;
				//SW
				if (test(x - 1, y + 1)) ++adjacentCount;
				//W
				if (test(x - 1, y)) ++adjacentCount;
				//NW
				if (test(x - 1, y - 1)) ++adjacentCount;

				if (adjacentCount < 4)
				{
					++count;
				}
			}
		}

		std::cout << count << std::endl;
	}
};

void Day4Part1() noexcept
{
	const Solution1 solution;
}



class Solution2
{
	std::string data{ readFile("Day4.txt") };
	int width{};
	int height{};

	bool test(int x, int y) const noexcept
	{
		return x >= 0 && x < width && y >= 0 && y < height && (data[y * width + x] == '@');
	}

public:

	Solution2() noexcept
	{
		//remove null terminator
		data.pop_back();
		width = static_cast<int>(std::distance(data.begin(), std::ranges::find(data, '\n'))) + 1;
		height = static_cast<int>(std::ranges::count(data, '\n') + 1);

		int count{};

		for (int y{}; y < height; ++y)
		{
			for (int x{}; x < width - 1; ++x)
			{
				int adjacentCount{};

				if (data[y * width + x] != '@')
				{
					continue;
				}

				//N
				if (test(x, y - 1)) ++adjacentCount;
				//NE
				if (test(x + 1, y - 1)) ++adjacentCount;
				//E
				if (test(x + 1, y)) ++adjacentCount;
				//SE
				if (test(x + 1, y + 1)) ++adjacentCount;
				//S
				if (test(x, y + 1)) ++adjacentCount;
				//SW
				if (test(x - 1, y + 1)) ++adjacentCount;
				//W
				if (test(x - 1, y)) ++adjacentCount;
				//NW
				if (test(x - 1, y - 1)) ++adjacentCount;

				if (adjacentCount < 4)
				{
					++count;
				}
			}
		}

		std::cout << count << std::endl;
	}
};

void Day4Part2() noexcept
{
	const Solution2 solution;
}

