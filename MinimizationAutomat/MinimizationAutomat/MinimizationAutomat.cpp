// MinimizationAutomat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct TransitionAndOutputState
{
	int transition;//переход
	int outPutstate;//выходное состояние
};

void readMili(vector<vector<TransitionAndOutputState>> & arrOfMili, ifstream & inFile, size_t countOfInputState, size_t countOfState);
vector<vector<TransitionAndOutputState>> getArrWithMinimizedMili(ifstream & inFile, size_t countOfInputState, size_t countOfOuputState, size_t countOfState);
vector<vector<TransitionAndOutputState>> getArrWithMinimizedMur(ifstream & inFile, size_t countOfInputState, size_t countOfOuputState, size_t countOfState);
void PrintArr(vector<vector<TransitionAndOutputState>> arrOfMili, int is, int js);
vector<vector<int>> getArrFromFirstItMilli(vector<vector<TransitionAndOutputState>> arrOfMili, size_t countOfInputState, size_t countOfState);
vector<vector<int>> getArrFromFirstItMur(vector<vector<int>> arrOfMur, size_t countOfInputState, size_t countOfState);
void PrintArrEqv(vector<vector<int>>  arrOfMili, int is, int js);
void readMur(vector<vector<int>> & arrofMur, ifstream & inFile, size_t countOfInputState, size_t countOfState);

const int MUR = 1;
const int MILI = 2;

int main()
{
	ifstream inFile("in2Mur.txt");
	ofstream outFile("output.txt");

	size_t stateForm;
	inFile >> stateForm;
	size_t countOfOutputState;
	size_t countOfInputState;
	size_t countOfState;

	inFile >> countOfInputState;
	inFile >> countOfOutputState;
	inFile >> countOfState;
	if (stateForm == MILI)
		vector<vector<TransitionAndOutputState>> ArrWithMinimizedMili = getArrWithMinimizedMili(inFile, countOfInputState, countOfOutputState, countOfState);
	else
		vector<vector<TransitionAndOutputState>> ArrWithMinimizedMili = getArrWithMinimizedMur(inFile, countOfInputState, countOfOutputState, countOfState);


	system("pause");
    return 0;
}

void readMur(vector<vector<int>> & arrofMur, ifstream & inFile, size_t countOfInputState, size_t countOfState) 
{
	for (size_t i = 0; i < countOfInputState + 1; i++)
		for (size_t j = 0; j < countOfState; j++)
			inFile >> arrofMur[i][j];
}

void readMili(vector<vector<TransitionAndOutputState>> & arrOfMili, ifstream & inFile, size_t countOfInputState, size_t countOfState)
{
	for (size_t i = 0; i < countOfInputState; i++)
		for (size_t j = 0; j < countOfState; j++)
		{
			inFile >> arrOfMili[i][j].transition;
			inFile >> arrOfMili[i][j].outPutstate;
		}
}

vector<vector<TransitionAndOutputState>> getArrWithMinimizedMili(ifstream & inFile, size_t countOfInputState, size_t countOfOuputState, size_t countOfState)
{
	vector<vector<TransitionAndOutputState>> arrOfMili(countOfInputState, vector<TransitionAndOutputState>(countOfState));

	readMili(arrOfMili, inFile, countOfInputState, countOfState);
	PrintArr(arrOfMili, countOfInputState, countOfState);
	vector<vector<int>> arrWithFirstEquvivalents(countOfInputState + 2, vector<int>(countOfState));
	arrWithFirstEquvivalents = getArrFromFirstItMilli(arrOfMili, countOfInputState, countOfState);
	PrintArrEqv(arrWithFirstEquvivalents, countOfInputState + 2, countOfState);

	return vector<vector<TransitionAndOutputState>>();
}

vector<vector<TransitionAndOutputState>> getArrWithMinimizedMur(ifstream & inFile, size_t countOfInputState, size_t countOfOuputState, size_t countOfState)
{
	vector<vector<int>> arrOfMur(countOfInputState + 1, vector<int>(countOfState));
	readMur(arrOfMur, inFile, countOfInputState, countOfState);
	vector<vector<int>> arrWithFirstEquvivalents(countOfInputState + 2, vector<int>(countOfState));
	arrWithFirstEquvivalents = getArrFromFirstItMur(arrOfMur, countOfInputState, countOfState);
	PrintArrEqv(arrWithFirstEquvivalents, countOfInputState + 2, countOfState);
	return vector<vector<TransitionAndOutputState>>();
}

vector<vector<int>> getArrFromFirstItMur(vector<vector<int>> arrOfMur, size_t countOfInputState, size_t countOfState)
{
	size_t countEquivalent = 0;
	set<int> setWithStates;
	vector<vector<int>> arrForOut(countOfInputState + 2, vector<int>(countOfState));
	size_t counter = 0;
	set<int> setForCheck;
	size_t countForCheck = 0;

	for (size_t i = 0; i < countOfState; i++)
	{
		countForCheck = setForCheck.size();
		for (size_t j = i; j < countOfState; j++)
		{
			if (arrOfMur[0][i] == arrOfMur[0][j] && (setForCheck.find(j) == setForCheck.end()))
			{
				setForCheck.insert(j);
				arrForOut[0][counter] = countEquivalent;
				arrForOut[1][counter] = j;
				counter++;
			}

		}

		if(countForCheck != setForCheck.size())
			countEquivalent++;
	}

	return arrForOut;
}

vector<vector<int>> getArrFromFirstItMilli(vector<vector<TransitionAndOutputState>> arrOfMili, size_t countOfInputState, size_t countOfState)
{
	int counter = 0;
	vector<vector<int>> arrForOut(countOfInputState+2, vector<int>(countOfState));
	set<int> setWithStates;
	bool isEquivalent = true;
	int countEquivalent = 0;
	int countForCheck = 0;
	set<int> setForCheck;

	for (size_t i = 0; i < countOfState; i++)
	{
		setForCheck = setWithStates;
		countForCheck = setWithStates.size();
		for (size_t j = i; j < countOfState; j++)
		{
			for (size_t k = 0; k < countOfInputState; k++)
				if (!(arrOfMili[k][i].outPutstate == arrOfMili[k][j].outPutstate && setWithStates.find(j) == setWithStates.end()))
				{
					isEquivalent = false;
					break;
				}

			if (isEquivalent)
				setWithStates.insert(j);
			else
				isEquivalent = true;
		}

		if (countForCheck != setWithStates.size())
		{
			bool isCheck = false;

			for (auto x : setWithStates)
			{
				isCheck = false;

				for (auto y : setForCheck)
					if (x == y)
						isCheck = true;

				if (!isCheck)
				{
					arrForOut[0][counter] = countEquivalent;
					arrForOut[1][counter] = x;
					counter++;
				}
			}

			countEquivalent++;
		}
	}
	
	return arrForOut;
}

void PrintArr(vector<vector<TransitionAndOutputState>> arrOfMili, int is, int js)
{
	for (size_t i = 0; i < is; i++)
	{
		for (size_t j = 0; j < js; j++)
			cout << arrOfMili[i][j].transition << '/' << arrOfMili[i][j].outPutstate << ' ';
		cout << endl;
	}
}

void PrintArrEqv(vector<vector<int>> arrOfMili, int is, int js)
{
	for (size_t i = 0; i < is; i++)
	{
		for (size_t j = 0; j < js; j++)
			cout << arrOfMili[i][j] << ' ';
		cout << endl;
	}
}