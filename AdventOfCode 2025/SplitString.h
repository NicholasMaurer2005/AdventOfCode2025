#pragma once

#include <string_view>



class SplitString
{
public:

	class Iterator
	{
	private:

		const char* m_dataBegin;
		const char* m_dataEnd;
		const char* m_currentBegin;
		const char* m_currentEnd;
		char m_character;



	public:

		using value_type = std::string_view;
		using difference_type = std::ptrdiff_t;
		using reference = std::string_view;
		using iterator_category = std::forward_iterator_tag;
		using pointer = std::string_view*;



	public:

		Iterator(std::string_view data, std::string_view current, char character) noexcept;

		//needed for std::ranges algorithms
		Iterator() noexcept = default;

		Iterator& operator++() noexcept;

		Iterator operator++(int) noexcept;

		std::string_view operator*() const noexcept;

		bool operator==(const Iterator& other) const noexcept;

		bool operator!=(const Iterator& other) const noexcept;
	};



private:

	std::string_view m_data;
	char m_character;



public:

	SplitString(std::string_view data, char character) noexcept;

	SplitString::Iterator begin() const noexcept;

	SplitString::Iterator end() const noexcept;
};

