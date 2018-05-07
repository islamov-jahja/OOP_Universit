// labyrinth.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	if (!IsCorrectCountOfArgumetns(argc, argv))
	{
		cout << "Incorrect count of arguments" << endl;
		system("pause");
		return 1;
	}

	ifstream inFile(argv[1]);

	if (!FileIsOpen(inFile))
	{
		cout << "File not open" << endl;
		system("pause");
		return 1;
	}

	ofstream outFile(argv[2]);
	int widthOfMaze = 0;
	int lengthOfMaze = 0;

	CalculateLengthAndWidthOfTheMaze(widthOfMaze, lengthOfMaze, inFile);
	vector<vector<char>> fieldOfLabyrinth(widthOfMaze, vector<char>(lengthOfMaze));
	CreateLabyrinthField(fieldOfLabyrinth, inFile);
	Point starPoint;
	Point endPoint;
	starPoint = SearcPointInArr(fieldOfLabyrinth, lengthOfMaze, START_POINT);
	endPoint = SearcPointInArr(fieldOfLabyrinth, lengthOfMaze, END_POINT);
	stack<StackData> wayToEndPoint;
	PathSearch(fieldOfLabyrinth, wayToEndPoint, starPoint);
	PathmarkInLabyrinth(wayToEndPoint, fieldOfLabyrinth, starPoint);
	PrintLabyrinth(fieldOfLabyrinth, lengthOfMaze, outFile);

	system("pause");
    return 0;
}