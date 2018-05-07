// calculatorver2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CControlCalculator.h"


int main()
{
	CControlCalculator calculator;
	string command;
	while (command != "...")
	{
		cout << "Enter your command. For exit write ..." << endl;
		getline(cin, command);
		if (command == "...")
			break;
		
		calculator.HandleCommand(command);
	}

	system("pause");
}

