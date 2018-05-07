// ProstoechisloOOP44.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <set>;
#include <iostream>
#include <cstdlib>;
#include <iterator>;
#include <vector>;
#include <string>;
using namespace std;

const long long int MAX_INT = 100000000;
const long long int SIZE = 100000010;
const int MIN = 1;
const int ERROR_ARGUMENTS = 2;
const int ERROR_INPUT_NUMBER_SO_BIG = 3;
const int ERROR_NUMBER = 4;

set<long long int> GetSet(long long int);
vector<int> GetEratosthenArr(long long int);
void CheckCountOfArguments(int);
void CheckInputLine(string);
void CheckForOverflow(long long int);

int main(int argc, char* argv[])
{
	long long int number;
	set<long long int> eratosthenesSieve;

	CheckCountOfArguments(argc);
	string inputLine = argv[1];
	CheckInputLine(inputLine);
	number = atoi(argv[1]);
	CheckForOverflow(number);
	eratosthenesSieve = GetSet(number);
	//copy(eratosthenesSieve.begin(), eratosthenesSieve.end(), ostream_iterator<long long int>(cout, " ")); 
	cout << eratosthenesSieve.size()+1;
	system("pause");
    return 0;
}

set<long long int> GetSet(long long int number)
{
	set<long long int> eratosthenesSieve;
	vector<int>eratosthenArr(SIZE);

	eratosthenesSieve.insert(2);
	eratosthenesSieve.insert(3);

	eratosthenArr = GetEratosthenArr(number);

	for (long long int i = 3; i <= number; i = i + 2)
	{
		if (i % 10 == 5 && i > 10)
			continue;
		if (eratosthenArr[i] != 1)
			eratosthenesSieve.insert(i);
	}

	return eratosthenesSieve;
}

vector<int> GetEratosthenArr(long long int number)
{
	vector <int> eratosthenArr(SIZE);

	for (long long int i = 2; i <= sqrt(number); i++)
	{
		if (eratosthenArr[i] == 1)
			continue;
		for (long long int j = i*i; j <= number; j += i) {
			if (j > number)
				break;
			eratosthenArr[j] = 1;
		}
	}

	return(eratosthenArr);
}

void CheckCountOfArguments(int argc)
{
	if (argc != 2)
	{
		cout << "wrong number of arguments. Enter the number to which you want to find prime numbers.";
	    exit(ERROR_ARGUMENTS);
	}
}

void CheckInputLine(string inputLine)
{
	for(auto x : inputLine)
		if (x < '0' || x > '9')
		{
			cout << "The entered string contains a letter, and there must be only a number";
			exit(ERROR_NUMBER);
		}
}

void CheckForOverflow(long long int number)
{
	if (number > MAX_INT || number < 1)
	{
		cout << "the number must be in the interval 1..100000000";
		exit(ERROR_INPUT_NUMBER_SO_BIG);
	}
}