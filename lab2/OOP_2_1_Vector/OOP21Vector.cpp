// OOP21Vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

const int ERROR_NUMBER = 1;

void Update(vector<float>&, float);
void InputToVector(vector<float>&);
void Show(vector<float>&);

float GetNumber(string);

int main(int argc, char *argv[])
{
	float factor;
	vector<float> arrOfNumber;

	InputToVector(arrOfNumber);
	sort(arrOfNumber.begin(), arrOfNumber.end());
	factor = *arrOfNumber.begin();
	Update(arrOfNumber, factor);
	Show(arrOfNumber);

    return 0;
}

void Update(vector<float>& arrOfNumber, float factor) 
{
	for (int i = 0; i < arrOfNumber.size(); i++)
		arrOfNumber[i] *= factor;
}

void InputToVector(vector<float>& arrOfNumber)
{
	string inputLine;
	float floatNumber;
	while (cin >> inputLine)
	{
		floatNumber = GetNumber(inputLine);
		arrOfNumber.push_back(floatNumber);
	}
}

void Show(vector<float>& arrOfNumber)
{
	cout << fixed;
	cout.precision(3);
	copy(arrOfNumber.begin(), arrOfNumber.end(), ostream_iterator<float>(cout, " "));
}

float GetNumber(string inputLine)
{
	float number = 0;
	for (auto x : inputLine)
		if ((x < '0' || x > '9') && x != '.')
		{
			cout << "The entered string contains a letter, and there must be only a number";
			exit(ERROR_NUMBER);
		}
	return strtod(inputLine.c_str(), nullptr);
}