/*
	Name: Jacob McGuire
	File: word.h
	Date: 12 / 13 / 18
*/

#ifndef WORD_H
#define WORD_H

#include<vector>
#include<string>

class Word
{
	public:
	Word(std::string word, int line);

	void add_word(int line);

	std::string get_word() const;

	std::vector<int> get_lines() const;

	int get_count() const;
private:
	std::string m_word;
	std::vector<int> m_lines;
	int m_count;
};

#endif
