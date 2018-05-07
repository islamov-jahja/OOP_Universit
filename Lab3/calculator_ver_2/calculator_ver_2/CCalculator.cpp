#include "stdafx.h"
#include "CCalculator.h"


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}

meanOfVariable CCalculator::GetValueOfVariable(string nameOfVariable)const
{
	pair<string, double> valueOfVariable;
	if (m_mapWithVariables.find(nameOfVariable) != m_mapWithVariables.end())
	{
		valueOfVariable = *m_mapWithVariables.find(nameOfVariable);
		return meanOfVariable("", valueOfVariable.second);
	}

	return meanOfVariable(NOT_FOUND, 0);
}

variableMap CCalculator::GetAllVariable() const
{
	return m_mapWithVariables;
}

meanOfVariable CCalculator::GetValueOfFunction(string nameOfVariable)
{
	if (m_mapWithFunctions.find(nameOfVariable) != m_mapWithFunctions.end())
	{
		double value;
		CalculateFunctioValue(nameOfVariable, value);
		return meanOfVariable(nameOfVariable, value);
	}
	else
		return meanOfVariable(NOT_FOUND, 0);

}

functionMap CCalculator::GetFunctionValues() const
{
	return m_mapWithFunctions;
}

int CCalculator::CreatNewVariable(string nameOfVariable)
{
	if (IsIdentifier(nameOfVariable))
		if (GetValueOfVariable(nameOfVariable).first == NOT_FOUND && GetValueOfFunction(nameOfVariable).first == NOT_FOUND)
		{
			m_mapWithVariables.insert(meanOfVariable(nameOfVariable, NAN));
			return 0;
		}
		else
			return 2;
	else
		return 1;
}

int CCalculator::ChangeValueOfIdentifier(string nameOfVariable, string nameOfVariable2)
{
	if (GetValueOfVariable(nameOfVariable).first != NOT_FOUND)
	    m_mapWithVariables.erase(nameOfVariable);

	if (GetValueOfFunction(nameOfVariable).first != NOT_FOUND)
		return 4;

	if (IsIdentifier(nameOfVariable))
	{
		if (GetValueOfVariable(nameOfVariable2).first != NOT_FOUND)
		{
			m_mapWithVariables.insert(meanOfVariable(nameOfVariable, GetValueOfVariable(nameOfVariable2).second));
			return 0;
		}
		else
		{
			if (GetValueOfFunction(nameOfVariable2).first != NOT_FOUND)
			{
				m_mapWithVariables.insert(meanOfVariable(nameOfVariable, GetValueOfFunction(nameOfVariable2).second));
				return 0;
			}
			else
				return 2;
		}
	}
	else
		return 1;
}

int CCalculator::ChangeValueOfIdentifier(string nameOfVariable, double value)
{
	if (GetValueOfVariable(nameOfVariable).first != NOT_FOUND)
		m_mapWithVariables.erase(nameOfVariable);

	if (IsIdentifier(nameOfVariable))
	{
		m_mapWithVariables.insert(meanOfVariable(nameOfVariable, value));
		return 0;
	}
	else
		return 1;
}


int CCalculator::CreatNewFunction(string nameOfValue, string nameOfValue2)
{
	if (IsFunctionExists(nameOfValue))
		return 3;

	if (IsIdentifier(nameOfValue))
	{
		if (GetValueOfVariable(nameOfValue2).first != NOT_FOUND)
		{
			m_mapWithFunctions.insert(pair<string, string>(nameOfValue, nameOfValue2));
			return 0;
		}
		else

		{
			if (GetValueOfFunction(nameOfValue2).first != NOT_FOUND)
			{
				m_mapWithFunctions.insert(pair<string, string>(nameOfValue, nameOfValue2));
				return 0;
			}
			else
				return 2;
		}
	}
	else
		return 1;
}

int CCalculator::CreatNewFunction(string nameOfValue, string nameOfValue2, char operation, string nameOfValue3)
{
	if (IsFunctionExists(nameOfValue))
		return 3;

	if (IsIdentifier(nameOfValue))
	{
		if (!IsFunctionExists(nameOfValue2))
			return 2;
		if (!IsFunctionExists(nameOfValue3))
			return 2;

		m_mapWithFunctions.insert(pair<string, string>(nameOfValue, nameOfValue2 + operation + nameOfValue3));
		return 0;
	}
	else
		return 1;
}

bool CCalculator::IsIdentifier(string nameOfIdentifier)const
{
	if (nameOfIdentifier.empty())
		return false;
	if (nameOfIdentifier[0] >= '0' && nameOfIdentifier[0] <= '9')
		return false;


	for (size_t i = 0; i < nameOfIdentifier.length(); i++)
		if (nameOfIdentifier[i] < '0' || (nameOfIdentifier[i] > '9' && nameOfIdentifier[i] < 'A' && nameOfIdentifier[i] > 'Z' && nameOfIdentifier[i] < '_' && nameOfIdentifier[i] > '_' && nameOfIdentifier[i] < 'a' && nameOfIdentifier[i] > 'z'))
			return false;

	return true;
}

bool CCalculator::IsFunctionExists(string nameOfFunction)
{
	if (GetValueOfFunction(nameOfFunction).first == NOT_FOUND)
	    if (GetValueOfVariable(nameOfFunction).first == NOT_FOUND)
		    return false;

	return true;
}

bool CCalculator::InitializateOfOperation(string inputLine, string & nameOfValue1, string & nameOfValue2, char & operation)
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
		nameOfValue1 = inputLine.substr(0, inputLine.find(operation));
		nameOfValue2 = inputLine.substr(inputLine.find(operation) + 1, inputLine.length());
		return (true);
	}
	else
		return (false);
}

double CCalculator::ExecuteOperation(char operation, double value1, double value2)
{
	if (isnan(value1) || isnan(value2))
		return (NAN);

	switch (operation)
	{
	    case '+':
	    	return(value1 + value2);
    	case '-':
	    	return(value1 - value2);
	    case '*':
		    return(value1 * value2);
	    case '/':
		{
			if (value2 == 0)
				return NAN;
			else
			    return(value1 / value2);
		}
	}
}

void CCalculator::CalculateFunctioValue(string nameOfFunction, double & value)
{
	string nameOfValue1;
	string nameOfValue2;
	char operation;
	string mainOperation;

	if (m_mapWithFunctions.find(nameOfFunction) != m_mapWithFunctions.end())
	    mainOperation = pair<string, string>(*m_mapWithFunctions.find(nameOfFunction)).second;
	else
		mainOperation = nameOfFunction;

	bool isOperation = InitializateOfOperation(mainOperation, nameOfValue1, nameOfValue2, operation);

	if (isOperation)
	{
		double value1;
		double value2;
		CalculateFunctioValue(nameOfValue1, value);
		value1 = value;
		CalculateFunctioValue(nameOfValue2, value);
		value2 = value;
		value = ExecuteOperation(operation, value1, value2);
	}
	else if (GetValueOfFunction(mainOperation).first != NOT_FOUND)
	{
		CalculateFunctioValue(mainOperation, value);
	}
	else
        value = GetValueOfVariable(mainOperation).second;
}
