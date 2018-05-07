// TranslatorOOP232.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <windows.h>
#include <clocale>
using namespace std;

const int ERROR_ARGUMENTS = 1;

map<string, string> GetDictionaryMap(ifstream&);
void WriteNewWord(string, map<string, string>&, map<string, string>&);
void EndTheProgram(ofstream&, map<string, string>, bool*);
void CheckFileForAvailabilityAndReadfromFile(ifstream&, map<string, string>&, bool*);

int main(int argc, char *argv[])
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "rus");

	map<string, string> dictionaryMap;
	map<string, string> mapForWriteToFile;
    ifstream dictionaryFileForRead(argv[1]);
	bool isNewFile;

	CheckFileForAvailabilityAndReadfromFile(dictionaryFileForRead, dictionaryMap, &isNewFile);

	ofstream dictionaryFileForWrite(argv[1], ios::app);
	string wordToSearch;
	pair<string, string> myPair;

	while (wordToSearch != "...")
	{
		cout << "enter a word or phrase for translation. to exit the program, write \"...\" " << endl;
		getline(cin, wordToSearch);

		if (wordToSearch == "...")
		{
			EndTheProgram(dictionaryFileForWrite, mapForWriteToFile, &isNewFile);
		}

		transform(wordToSearch.begin(), wordToSearch.end(), wordToSearch.begin(), tolower);

		if (dictionaryMap.find(wordToSearch) != dictionaryMap.end())
		{
			myPair = *dictionaryMap.find(wordToSearch);
            cout << myPair.second << endl;
		}
		else
		{
			WriteNewWord(wordToSearch, dictionaryMap, mapForWriteToFile);
		}
	}
	
    return 0;
}


map<string, string> GetDictionaryMap(ifstream &dictionaryFile)
{
	map<string, string> dictionaryMap;
	string line1, line2;

	while (!dictionaryFile.eof())
	{
		getline(dictionaryFile, line1);
		getline(dictionaryFile, line2);
		transform(line1.begin(), line1.end(), line2.begin(), tolower);
		dictionaryMap.insert(pair<string, string>(line1, line2));
	}

	return dictionaryMap;
}

void WriteNewWord(string wordToSearc, map<string, string> &dictionaryMap, map<string, string> &mapForWriteToFile)
{
	string userResponse;
	string wordToWrite;

	cout << "translation not found. Would you like to add a translation of this word? Y - yes, N - no" << endl;
	getline(cin, userResponse);

	if (userResponse == "Y")
	{
		cout << "enter the translation of the word" << endl;
		getline(cin, wordToWrite);
		dictionaryMap.insert(pair<string, string>(wordToSearc, wordToWrite));
		mapForWriteToFile.insert(pair<string, string>(wordToSearc, wordToWrite));
		cout << "the word \"" << wordToSearc << "\" is saved as \"" << wordToWrite << "\"" << endl;
	}
	else if (userResponse != "N")
		WriteNewWord(wordToSearc, dictionaryMap, mapForWriteToFile);
}

void EndTheProgram(ofstream &dictionaryFile, map<string, string> mapForWriteToFile, bool* isNewFile)
{
	string userResponse;

	if (mapForWriteToFile.size() == 0)
	{
		dictionaryFile.close();
		exit(0);
	}
	else
	{
		cout << "Save translations of new words in the dictionary file? Y - yes, N - no" << endl;
		getline(cin, userResponse);
		if (userResponse == "Y")
		{
			for (auto x : mapForWriteToFile)
			{
				if (!*isNewFile)
					dictionaryFile << endl;
				else
					*isNewFile = false;
				dictionaryFile << x.first << endl;
				dictionaryFile << x.second;
			}
			dictionaryFile.close();
			cout << "all words have been saved" << endl;
			system("pause");
			exit(0);
		}
		else if (userResponse == "N")
		{
			dictionaryFile.close();
			exit(0);
		}
		else
			EndTheProgram(dictionaryFile, mapForWriteToFile, isNewFile);
	}
}

void CheckFileForAvailabilityAndReadfromFile(ifstream &dictionaryFileForRead, map<string, string> &dictionaryMap, bool* isNewFile)
{
	if (dictionaryFileForRead.is_open())
	{
		dictionaryMap = GetDictionaryMap(dictionaryFileForRead);
		dictionaryFileForRead.close();
		*isNewFile = false;
	}
	else
		*isNewFile = true;
}