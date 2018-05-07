#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Stack>

using namespace std;

struct Point {
	int x, y;
};

typedef pair<Point, vector<vector<char>>> StackData;

const char START_POINT = 'A';
const char END_POINT = 'B';

bool IsCorrectCountOfArgumetns(int argc, char* argv[]);
bool FileIsOpen(ifstream& inFile);
void CalculateLengthAndWidthOfTheMaze(int& width, int& length, ifstream& inFile);
void CreateLabyrinthField(vector<vector<char>>& field, ifstream& inFile);
Point SearcPointInArr(vector<vector<char>> arr, const int& length, const char& point);
void PathSearch(vector<vector<char>> fieldOfLabyrinth, stack<StackData>& wayToEndPoint, const Point& startPoint);
void QueueInsertion(int x, int y, Point & point, stack<StackData>& wayToEndPoint, const vector<vector<char>>& fieldOfLabyrinth);
void PathmarkInLabyrinth(stack<StackData>& wayToEndPoint, vector<vector<char>>& fieldOfLabyrinth, Point startPoint);
void PrintLabyrinth(const vector<vector<char>>& fieldOfLabyrinth, const int& length, ofstream& outFile);