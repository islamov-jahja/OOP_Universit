// GeomFigure.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CGeomFigureControl.h";d;

int main()
{
	string command;
	CGeomFigureControl addedFigures;
	while (command != "...")
	{
		cout << "Enter name of the figure. Enter \"...\" for exit" << endl;
		cin >> command;
		addedFigures.ExecuteTheCommand(command);
	}
	addedFigures.ExecuteTheCommand("Max area");
	addedFigures.ExecuteTheCommand("Min perimeter");
	addedFigures.~CGeomFigureControl();
	system("pause");
    return 0;
}

