// CStringStack.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CStringStack.h";

int main()
{
	CStringStack stack;
	stack.Push("hello");
	cout << stack.Top();
	system("pause");
    return 0;
}

