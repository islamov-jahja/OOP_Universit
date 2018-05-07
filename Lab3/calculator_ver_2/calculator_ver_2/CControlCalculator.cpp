#include "stdafx.h"
#include "CControlCalculator.h"
const string PRINT = "print";
const string PRINT_VARS = "printvars";
const string PRINT_FUNCTIONS = "printfns";
const string CREAT_FUNCTION = "fn";
const string CREAT_VARS = "var";
const string CREAT_OR_CHANGE_VAR = "let";

CControlCalculator::CControlCalculator()
{
}

void CControlCalculator::HandleCommand(string & command)
{
	if (command.find(CREAT_VARS) == 0)
		CreatVar(command);
	else if (command.find(CREAT_OR_CHANGE_VAR) == 0)
		CreatOrChangeVar(command);
	else if (command.find(PRINT_VARS) == 0)
		PrintVars(command);
	else if (command.find(PRINT_FUNCTIONS) == 0)
		PrintFunctions(command);
	else if (command.find(CREAT_FUNCTION) == 0)
		CreatFunction(command);
	else if (command.find(PRINT) == 0)
		Print(command);
	else
		cout << "command not found" << endl;
}


CControlCalculator::~CControlCalculator()
{
}

void CControlCalculator::Print(const string & command)
{
	cout << fixed;
	cout.precision(2);
	string nameOfValue;
	nameOfValue = command.substr(PRINT.length() + 1, command.length());
	if (m_calculator.GetValueOfVariable(nameOfValue).first != NOT_FOUND)
		cout << m_calculator.GetValueOfVariable(nameOfValue).second << endl;
	else if (m_calculator.GetValueOfFunction(nameOfValue).first != NOT_FOUND)
		cout << m_calculator.GetValueOfFunction(nameOfValue).second << endl;
	else
		cout << "Variable not Found";

}

void CControlCalculator::PrintVars(const string & command) const
{
	variableMap mapWithVariables = m_calculator.GetAllVariable();
	for (auto x : mapWithVariables)
		cout << x.first << ' ' << x.second << endl;
}

void CControlCalculator::PrintFunctions(const string & command)
{
	functionMap mapWithFunctions = m_calculator.GetFunctionValues();
	for (auto x : mapWithFunctions)
		cout << x.first << ' ' << m_calculator.GetValueOfFunction(x.first).second << endl;
}

void CControlCalculator::CreatFunction(const string & command)
{
	int resultOfOperation;
	string nameOfValue2 = command.substr(command.find("=") + 1, command.length());
	string nameOfValue1 = command.substr(CREAT_FUNCTION.length() + 1, command.length() - 4 - nameOfValue2.length());
	string valueInCalculation1, valueInCalculation2;
	char operation;
	bool isOperation;
	isOperation = InitializationOfOperations(nameOfValue2, valueInCalculation1, valueInCalculation2, operation);
	if (isOperation)
	{
		resultOfOperation = m_calculator.CreatNewFunction(nameOfValue1, valueInCalculation1, operation, valueInCalculation2);
		PrintResultOfOperation(resultOfOperation);
	}
	else
	{
		resultOfOperation = m_calculator.CreatNewFunction(nameOfValue1, nameOfValue2);
		PrintResultOfOperation(resultOfOperation);
	}
}

void CControlCalculator::CreatVar(const string & command)
{
	string nameOfValue = command.substr(CREAT_VARS.length() + 1, command.length());
	int result = m_calculator.CreatNewVariable(nameOfValue);
	PrintResultOfOperation(result);
}

void CControlCalculator::CreatOrChangeVar(const string & command)
{
	int resultOfOperation;
	double value;
	string nameOfValue2 = command.substr(command.find("=") + 1, command.length());
	string nameOfValue1 = command.substr(CREAT_OR_CHANGE_VAR.length() + 1, command.length() - 5 - nameOfValue2.length());
	if (IsNumber(nameOfValue2))
	{
		value = strtod(nameOfValue2.c_str(), nullptr);
		resultOfOperation = m_calculator.ChangeValueOfIdentifier(nameOfValue1, value);
		PrintResultOfOperation(resultOfOperation);
	}
	else
	{
		resultOfOperation = m_calculator.ChangeValueOfIdentifier(nameOfValue1, nameOfValue2);
		PrintResultOfOperation(resultOfOperation);
	}

}

void CControlCalculator::PrintResultOfOperation(const int& result) const
{
	if (result == 0)
		cout << "operation completed successfully" << endl;
	else if (result == 1)
		cout << "identifier with this name is not allowed" << endl;
	else if (result == 2)
		cout << "such identifier already exists" << endl;
	else if (result == 3)
		cout << "identifier with this name is not allowed" << endl;
	else if (result == 4)
		cout << "you cannot change the value of a function" << endl;
}

bool CControlCalculator::IsNumber(const string& number)const
{
	int pointCounter = 0;
	for (size_t k = 0; k < number.length(); k++)
		if (number[k] == '.')
			pointCounter++;

	if (pointCounter > 1)
		return false;

	for (size_t k = 0; k < number.length(); k++)
		if (!((number[k] >= '0' && number[k] <= '9') || number[k] == '.'))
			return false;

	return true;
}

bool CControlCalculator::InitializationOfOperations(string inputLine, string& NameOfvalue1, string& NameOfvalue2, char& operation)
{
	operation = 'n';
	if (inputLine.find('+') != -1)
		operation = '+';
	else if (inputLine.find('-') != -1)
		operation = '-';
	else if (inputLine.find('*') != -1)
		operation = '*';
	else if (inputLine.find('/') != -1)
		operation = '/';

	if (operation != 'n')
	{
		NameOfvalue1 = inputLine.substr(0, inputLine.find(operation));
		NameOfvalue2 = inputLine.substr(inputLine.find(operation) + 1, inputLine.length());
		return (true);
	}
	else
		return (false);
}