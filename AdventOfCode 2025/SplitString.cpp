#include "SplitString.h"



//SplitString Iterator
SplitString::Iterator::Iterator(std::string_view data, std::string_view current, char character) noexcept :
	m_dataBegin(data.data()), m_dataEnd(data.data() + data.size()), 
	m_currentBegin(current.data()), m_currentEnd(current.data() + current.size()), 
	m_character(character)  { }

SplitString::Iterator& SplitString::Iterator::operator++() noexcept
{
	//I was going to do this 'std::min(m_dataEnd, m_currentEnd + 1)' but it is UB for some stupid reason
	//so instead I have to do 'm_currentEnd + (m_currentEnd < m_dataEnd ? 1 : 0)' which is way less readable
	//but it is not UB and is branchless. OH BOY! I LOVE C++

	const char* ptr{ std::find(std::min(m_dataEnd, m_currentEnd + (m_currentEnd < m_dataEnd ? 1 : 0)), m_dataEnd, m_character)};
	m_currentBegin = std::min(m_dataEnd, m_currentEnd + 1);
	m_currentEnd = ptr;

	return *this;
}

SplitString::Iterator SplitString::Iterator::operator++(int) noexcept
{
	Iterator temp = *this;
	++*this;

	return temp;
}

std::string_view SplitString::Iterator::operator*() const noexcept
{
	return std::string_view(m_currentBegin, m_currentEnd);
}

bool SplitString::Iterator::operator==(const Iterator& other) const noexcept
{
	return m_currentBegin == other.m_currentBegin && m_currentEnd == other.m_currentEnd;
}

bool SplitString::Iterator::operator!=(const Iterator& other) const noexcept
{
	return m_currentBegin != other.m_currentBegin || m_currentEnd != other.m_currentEnd;
}



//SplitString
SplitString::SplitString(std::string_view data, char character) noexcept
	: m_data(std::string_view(data.begin(), std::ranges::find(data, '\0'))), m_character(character) {}

SplitString::Iterator SplitString::begin() const noexcept
{
	const std::string_view current{ m_data.begin(), std::ranges::find(m_data, m_character) };
	return Iterator(m_data, current, m_character);
}

SplitString::Iterator SplitString::end() const noexcept
{
	const std::string_view current{ m_data.data() + m_data.size(), 0};
	return Iterator(m_data, current, m_character);
}