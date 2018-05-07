#pragma once
#include <string>
#include <iostream>
#include "CCalculator.h"
using namespace std;

class CControlCalculator
{
public:
	CControlCalculator();
	void HandleCommand(string& command);
	~CControlCalculator();
private:
	void Print(const string& command);
	void PrintVars(const string& command)const;
	void PrintFunctions(const string& command);
	void CreatFunction(const string& command);
	void CreatVar(const string& command);
	void CreatOrChangeVar(const string& command);
	void PrintResultOfOperation(const int& result)const;
	bool IsNumber(const string& number)const;
	bool InitializationOfOperations(string inputLine, string& NameOfvalue1, string& NameOfvalue2, char& operation);
	CCalculator m_calculator;
};

