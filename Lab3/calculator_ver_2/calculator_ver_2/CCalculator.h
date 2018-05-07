#pragma once
#include <map>
#include <iostream>
#include <string>
using namespace std;

const string NOT_FOUND = "Not found";
typedef map<string, double> variableMap;
typedef map<string, string> functionMap;
typedef pair<string, double> meanOfVariable;


class CCalculator
{
public:
	CCalculator();
	~CCalculator();
	meanOfVariable GetValueOfVariable(string nameOfVariable)const;
	variableMap GetAllVariable()const;
	meanOfVariable GetValueOfFunction(string nameOfVariable);
	functionMap GetFunctionValues()const;
	int CreatNewVariable(string nameOfVariable);
	int ChangeValueOfIdentifier(string nameOfVariable, string nameOfVariable2);
	int ChangeValueOfIdentifier(string nameOfVariable, double value);
	int CreatNewFunction(string, string);
	int CreatNewFunction(string, string, char, string);
private:
	bool IsIdentifier(string nameOfIdentifier)const;
	bool IsFunctionExists(string nameOfFunction);
	bool InitializateOfOperation(string inputLine, string& nameOfValue1, string& nameOfValue2, char& operation);
	double ExecuteOperation(char operation, double value1, double value2);
	void CalculateFunctioValue(string nameOfFunction, double& value);
	variableMap m_mapWithVariables;
	functionMap m_mapWithFunctions;
};

