#include "FunctionsForLabyrinth.h"


bool IsCorrectCountOfArgumetns(int argc, char* argv[])
{
	if (argc != 3)
		return false;
	return true;
}

bool FileIsOpen(ifstream& inFile)
{
	if (!inFile.is_open())
		return false;
	return true;
}

void CalculateLengthAndWidthOfTheMaze(int& width, int& length, ifstream& inFile)
{
	string str;

	while (!inFile.eof())
	{
		getline(inFile, str);
		width++;
		if (str.length() > length)
			length = str.length();
	}

	inFile.seekg(ios::beg);
}

void CreateLabyrinthField(vector<vector<char>>& field, ifstream& inFile)
{
	string str;
	for (size_t i = 0; i < field.size(); i++) {
		getline(inFile, str);
		for (int j = 0; j < str.length(); j++)
			field[i][j] = str[j];
	}
}

Point SearcPointInArr(vector<vector<char>> arr, const int& length, const char& point)
{
	Point myPoint;
	myPoint.x = 0;
	myPoint.y = 0;
	for (size_t i = 0; i < arr.size(); i++)
		for (size_t j = 0; j < length; j++)
			if (arr[i][j] == point)
			{
				myPoint.x = i;
				myPoint.y = j;
			}
	return myPoint;
}

void PathSearch(vector<vector<char>> fieldOfLabyrinth, stack<StackData>& wayToEndPoint, const Point& startPoint)
{
	Point point = startPoint;

	wayToEndPoint.push(StackData(startPoint, fieldOfLabyrinth));
	while (true)
	{
		point = wayToEndPoint.top().first;
		fieldOfLabyrinth = wayToEndPoint.top().second;

		if (fieldOfLabyrinth[point.x + 1][point.y] != '#')
		{
			if (fieldOfLabyrinth[point.x + 1][point.y] == END_POINT)
				break;
			fieldOfLabyrinth[point.x + 1][point.y] = '#';
			QueueInsertion(point.x + 1, point.y, point, wayToEndPoint, fieldOfLabyrinth);

		}
		else if (fieldOfLabyrinth[point.x - 1][point.y] != '#')
		{
			if (fieldOfLabyrinth[point.x - 1][point.y] == END_POINT)
				break;
			fieldOfLabyrinth[point.x - 1][point.y] = '#';
			QueueInsertion(point.x - 1, point.y, point, wayToEndPoint, fieldOfLabyrinth);
		}
		else if (fieldOfLabyrinth[point.x][point.y + 1] != '#')
		{
			if (fieldOfLabyrinth[point.x][point.y + 1] == END_POINT)
				break;
			fieldOfLabyrinth[point.x][point.y+1] = '#';
			QueueInsertion(point.x, point.y+1, point, wayToEndPoint, fieldOfLabyrinth);
		}
		else if (fieldOfLabyrinth[point.x][point.y - 1] != '#')
		{
			if (fieldOfLabyrinth[point.x][point.y - 1] == END_POINT)
				break;
			fieldOfLabyrinth[point.x][point.y-1] = '#';
			QueueInsertion(point.x, point.y-1, point, wayToEndPoint, fieldOfLabyrinth);
		}
		else {
			break;
		}
	}
}

void QueueInsertion(int x, int y, Point & point, stack<StackData>& wayToEndPoint, const vector<vector<char>>& fieldOfLabyrinth)
{
	point.x = x;
	point.y = y;
	wayToEndPoint.push(StackData(point, fieldOfLabyrinth));
}

void PathmarkInLabyrinth(stack<StackData>& wayToEndPoint, vector<vector<char>>& fieldOfLabyrinth, Point startPoint)
{
	while (wayToEndPoint.size()!=0)
	{

		if (wayToEndPoint.top().first.x != startPoint.x && wayToEndPoint.top().first.y != startPoint.y)
	    {
			fieldOfLabyrinth[wayToEndPoint.top().first.x][wayToEndPoint.top().first.y] = '.';
			wayToEndPoint.pop();
		}
	    else
			break;
	}
}

void PrintLabyrinth(const vector<vector<char>>& fieldOfLabyrinth, const int& length, ofstream& outFile)
{
	for (size_t i = 0; i < fieldOfLabyrinth.size(); i++)
	{
		for (size_t j = 0; j < length; j++)
			cout << fieldOfLabyrinth[i][j];
		cout << endl;
	}
}
 


