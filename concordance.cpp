#include "concordance.h"
#include <iomanip>
#include <cctype>

Index::Index(std::ifstream& input)
{
	std::vector<std::string> lines;
	std::string line;

	while (!input.eof())
	{
		std::getline(input, line); 
		format(line);
		lines.push_back(line);
	}

	std::vector<Word> buffer = get_words(lines);

	for (int i = 0; i < buffer.size(); i++)
	{
		add_word(buffer[i]); 
	}
}

std::string Index::format(std::string& line)
{
	std::string formatted_line;

	for (int i = 0; i < line.size(); i++)
	{
		line[i] = tolower(line[i]);
		if (!((line[i] >= 'a' && line[i] <= 'z') || line[i] == ' '))
		{
			line.erase(line.begin() + i);
			i--; 
		}
		if ((line[i] >= 'a' && line[i] <= 'z') || line[i] == ' ')
		{
			formatted_line += line[i];
		}
	}

	return formatted_line;
}

std::vector<Word> Index::get_words(const std::vector<std::string>& lines)
{
	std::vector<Word> words;
	std::string current_line, current_word;
	for (int line_count = 0; line_count < lines.size(); line_count++) // iterate through every line given
	{
		current_line = lines[line_count]; 
		current_line += ' '; 
		for (int pos = 0; pos < current_line.size(); pos++) 
		{
			if (!(is_whitespace(current_line[pos])))
			{
				current_word += current_line[pos];
			}
			if (current_word.size() != 0) 
			{
				if (is_whitespace(current_line[pos])) 
				{
					words.push_back(Word(current_word, line_count + 1));
					current_word += current_line[pos]; 
					current_word = ""; 
				}
			}
		}
	}
	return words;
}

bool Index::is_whitespace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

void Index::add_word(Word word)
{
	for (int i = 0; i < m_index.size(); i++)
	{
		if (word.get_word() == m_index[i].get_word())
		{
			int position = word.get_lines()[0]; 
			m_index[i].add_word(position);
			return; 
		}
	}
	m_index.push_back(word); 
}

std::ostream& Index::print(std::ostream& o)
{
	const int FIRST_COLUMN = 16;
	const int SECOND_COLUMN = 7; 

	o << std::setw(FIRST_COLUMN) << std::left << "Word";
	o << std::setw(SECOND_COLUMN) << std::left << "Count";
	o << "Line(s)";
	o << '\n';
	for (int i = 0; i < m_index.size(); i++)
	{
		o << std::setw(FIRST_COLUMN);
		o << m_index[i].get_word();
		o << std::setw(SECOND_COLUMN);
		o << m_index[i].get_count();
		for (int j = 0; j < m_index[i].get_lines().size(); j++)
		{
			o << m_index[i].get_lines()[j]; 
			if (j != m_index[i].get_lines().size() - 1)
			{
				o << ", ";
			}
		}
		o << '\n';
	}
}
