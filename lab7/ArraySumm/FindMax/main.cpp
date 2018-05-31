// FindMax.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "SummArray.h"


int main()
{
	vector<float> floatArr{ 2.51f, 3.53f, 65.1f };
	vector<int> intArr{ 1, 2 ,3 , 4 };
	vector<string> stringArr{ "hello", "world", "cat", "car", "dog" };
	cout << "summ Float: " << ArraySum(floatArr) << endl;
	cout << "summ Int: " << ArraySum(intArr) << endl;

	try
	{
		cout << "summ String: " << ArraySum(stringArr) << endl;
	}
	catch (const std::exception& e)
	{
		e.what();
	}

	system("pause");
    return 0;
}

