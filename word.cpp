/*
	Name: Jacob McGuire
	File: word.cpp
	Date: 12 / 13 / 18
*/

#include "word.h"

Word::Word(std::string word, int line)
{
	m_word = word;
	m_lines.push_back(line);
	m_count = 1;
}

void Word::add_word(int line)
{
	m_lines.push_back(line);
	m_count++;
}

std::string Word::get_word() const
{
	return m_word;
}

std::vector<int> Word::get_lines() const
{
	return m_lines;
}

int Word::get_count() const
{
	return m_count;
}
