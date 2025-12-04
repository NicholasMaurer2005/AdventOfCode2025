#include "Days.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <cstddef>
#include <iterator>

#include "Helper.h"
#include "SplitString.h"





class Solution
{
	std::string data;
	int width{ static_cast<int>(std::distance(data.begin(), std::ranges::find(data, '\n'))) + 1 };
	int height{ static_cast<int>(std::ranges::count(data, '\n') + 1) };

	bool test(int x, int y) const noexcept
	{
		return x >= 0 && x < width - 1 && y >= 0 && y < height && data[y * width + x] == '@';
	}

public:
	
	Solution(std::string_view dataIn) noexcept
		: data(dataIn)
	{
		//corners
		int count{};

		for (int y{}; y < height; ++y)
		{
			//width - 1 because of '\n'
			for (int x{}; x < width; ++x)
			{
				int adjacentCount{};

				const char c{ data[y * width + x] };
				if (c == '\n' || c != '@')
				{
					continue;
				}

				if (x == 7 && y == 0)
				{
					int nick{};
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
					data[y * width + x] = 'x';
				}
			}
		}

		std::cout << data << '\n';
		std::cout << count << std::endl;
	}
};

void Day4Part1() noexcept
{
	std::string data{ readFile("Day4.txt") };
	const Solution solution{ std::string_view(data.begin(), data.end() - 1) };
}

void Day4Part2() noexcept
{

}