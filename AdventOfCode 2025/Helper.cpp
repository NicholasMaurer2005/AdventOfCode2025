#include "Helper.h"

#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <chrono>
#include <format>
#include <iostream>



//track heap allocations
int heapAllocations{};
std::size_t heapUsage{};

void* operator new(std::size_t size)
{
	++heapAllocations;
	heapUsage += size;

	void* ptr{ std::malloc(size) };

	if (ptr)
	{
		return ptr;
	}
	else
	{
		throw std::bad_alloc();
	}
}



//performance logger
class PerfomanceLogger
{
private:

	std::chrono::high_resolution_clock::time_point start{ std::chrono::high_resolution_clock::now() };

public:

	~PerfomanceLogger()
	{
		const std::chrono::high_resolution_clock::time_point end{ std::chrono::high_resolution_clock::now() };
		const std::chrono::duration<double> elapsed{ end - start };

		std::cout << std::format("\n\n\nSolution ran in {} seconds ({}ms)\n\nSolution used {} heap allocation(s) ({}kb)\n\n\n", elapsed.count(), elapsed.count() * 1000, heapAllocations, static_cast<double>(heapUsage) / 1000.0);
	}
};

static PerfomanceLogger performanceLogger;



//Helper implementation
std::string readFile(std::string_view file) noexcept
{
	std::ifstream in{ file.data(), std::ios::ate };
	const std::size_t size{ static_cast<std::size_t>(in.tellg()) };
	in.seekg(0);

	std::string data;
	data.resize(size);
	in.read(data.data(), size);

	return data;
}


