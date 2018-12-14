/*
	Name: Jacob McGuire
	File: concordance.h
	Date: 12 / 13 / 18
*/

#ifndef CONCORDANCE_H
#ifndef INDEX_H
#define INDEX_H

#include "word.h"
#include<vector>
#include<fstream>

class Index
{
public:
	/*
		Will take a file as input and create an index of it
		@param input = a file to read from and create an index of
	*/
	Index(std::ifstream& input);

	/*
		Formats a string to be used in other functions with ease
		@param line = an individual line to format
		@return the formatted line
	*/
	std::string format(std::string& line);

	/*
		Pulls words out of a line and makes them into Word objects
		@param lines = a vector of lines to take words from
		@return a vector of Word objects where every word found in lines gets it's own position
	*/
	std::vector<Word> get_words(const std::vector<std::string>& lines);

	/*
		Determines if the character given is whitespace
		@return whether or not the character is whitespace
	*/
	bool is_whitespace(const char c);

	/*
		Adds Word objects to the member vector of Words making sure only unique words are added
			and any consecutive words will increase the count and add a new line number to the last
			occurrence of the word
		@param word = a Word object to be checked against the member vector
	*/
	void add_word(Word word);

	/*
		Formats output and sends it to the given stream (command-line or file)
		@param o = the destination for the output
		@return all unique words from the index in the form: word count line number, line number, etc.
	*/
	std::ostream& print(std::ostream& o);
private:
	std::vector<Word> m_index;
};

#endif
#endif

