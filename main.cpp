/*
	Name: Jacob McGuire
	File: main.cpp
	Date: 12 / 13 / 18
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "concordance.h"

void usage();

int main(int argc, char *argv[]) 
{
	if (argc > 1 && argc < 4)
	{
		std::string filename = argv[1];
		std::ifstream input;
		input.open(filename.c_str());

		if (!input.is_open())
		{
			std::cout << "Error opening file: " << filename << std::endl;
			return 1;
		}

		Index index(input);
		input.close();

		if (argc == 2) 
		{
			index.print(std::cout);
		}
		else if (argc == 3)
		{
			std::ofstream output;
			std::string outfile = argv[2]; // output file
			output.open(outfile.c_str());
			index.print(output);
			output.close();
		}
		else
		{
			usage();
		}
	}
	else
	{
		usage();
	}

	return 0;
}


void usage()
{
	std::cout << "Error:" << std::endl;
	std::cout << "./main [input file] [output destination]" << std::endl;
	std::cout << "  --Blank output destination prints output on command-line interface" << std::endl;
}