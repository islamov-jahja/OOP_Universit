// ReplaceText.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

const int PROBLEM_ARGUMENTS = 1;
const int FILE_NOT_FOUND = 2;
const int EMPTY_SEARCH_LINE = 3;

const int COUNT_OF_ARGUMENTS = 5;

int main(int argc, char* argv[])
{
	if (argc != COUNT_OF_ARGUMENTS)
	{
		cout << "Wrong number of arguments. This program replaces the string in the input file with another specific string, outputting the result to the second file. Please first enter the name of the program, then the name of the input file, the output file, the search string and the end of the replacement string." << endl;
		return PROBLEM_ARGUMENTS;
	}

	ifstream readFile(argv[1]);
	ofstream writeFile(argv[2]);
	string findLine(argv[3]);
	string replaceLine(argv[4]);
	string sourceLine;
	string str;

	if (!readFile.is_open())
	{
		cout << "Input file not found";
		return(FILE_NOT_FOUND);
	}

	if (!writeFile.is_open())
	{
		cout << "Output file not open";
		return(FILE_NOT_FOUND);
	}

	if (findLine == "")
	{
		cout << "search line is empty";
		return (EMPTY_SEARCH_LINE);
	}

	int indexOfFoundWord = 0;

	if (replaceLine != "")
	{
		while (!readFile.eof())
		{
			indexOfFoundWord = 0;
			getline(readFile, sourceLine);
			while (indexOfFoundWord != -1)
			{
				indexOfFoundWord = sourceLine.find(findLine);
				if (indexOfFoundWord != -1)
					for (int i = 0; i < indexOfFoundWord; i++)
						writeFile << sourceLine[i];
				else
				{
					writeFile << sourceLine;
					break;
				}

				writeFile << replaceLine;
				sourceLine = sourceLine.substr((indexOfFoundWord + findLine.length()), sourceLine.length() - (indexOfFoundWord + findLine.length() - 1));
				
			}
			writeFile << endl;
		}
	}
	else
	{
		while (!readFile.eof())
		{
			getline(readFile, sourceLine);
			writeFile << sourceLine << endl;
		}
	}

    return 0;
}

