// CMyArrayTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../CMyArray/CMyArray/CMyArray.h"
#include "../../CMyArray/CMyArray/CMyIterator.h"
#include "../../CMyArray/CMyArray/CReverseIt.h"
#include <iostream>
#include <vector>
using namespace std;

TEST_CASE("checking the iterator equality operator")
{
	cout << "--checking the iterator equality operator" << endl;
	int x = 5;
	CMyIterator<int> it(&x);
	CMyIterator<int> it2(&x);
	CHECK(it == it2);
	cout << "iterators are equal" << endl << endl;
}

TEST_CASE("check the iterator for inequality")
{
	cout << "--check the iterator for inequality" << endl;
	int x = 5;
	int y = 8;
	CMyIterator<int> it(&x);
	CMyIterator<int> it2(&y);
	CHECK(it != it2);
	cout << "iterators are not equal" << endl << endl;
}

TEST_CASE("verification of the assignment operator")
{
	cout << "--verification of the assignment operator" << endl;
	int x = 5;
	CMyIterator<int> it(&x);
	CMyIterator<int> it2;
	it2 = it;
	CHECK(it == it2);
	cout << "the iterator is assigned correctly" << endl << endl;
}

TEST_CASE("checking the method of obtaining the value of the iterator")
{
	cout << "--checking the method of obtaining the value of the iterator" << endl;
	int x = 5;
	CMyIterator<int> it(&x);
	CHECK(it.GetValue() == 5);
	cout << "the value is correct" << endl << endl;
}

TEST_CASE()
{
	cout << "--checking ++ and --" << endl;
	vector<int> number(2, 3);
	CMyIterator<int> it = &number[0];
	it++;
	CHECK(it.GetValue() == 3);
	cout << "the test was successful" << endl << endl;
}

TEST_CASE()
{
	cout << "--checking ++ and -- from" << endl;
	vector<int> number {2, 4 ,5};
	CMyIterator<int> it = &number[1];
	CMyIterator<int> it2 = ++it;
	CMyIterator<int> it3 = --it;
	CHECK(it2.GetValue() == 5);
	CHECK(it.GetValue() == 4);
	CHECK(it3.GetValue() == 4);
	CHECK(it.GetValue() == 4);
	cout << "the test was successful" << endl << endl;
}

TEST_CASE("Check ++ and -- reverse iterator")
{
	cout << "--Check ++ and -- reverse iterator" << endl;
	CMyArray<int> arr{ 2, 4, 5, 8 };
	CReverseIt<int> revIt = &arr[3];
	revIt++;
	CHECK(revIt.GetValue() == 5);
	revIt = &arr[0];
	revIt--;
	CHECK(revIt.GetValue() == 4);
	cout << "the test was successful" << endl << endl;
}

TEST_CASE("bracelet constructor test")
{
	cout << "--bracelet constructor test" << endl;
	CMyArray<int> myArr{4, 2, 1};
	CHECK(myArr.Size() == 3);
	CHECK(myArr[2] == 1);
	CHECK(myArr[0] == 4);
	CHECK(myArr[1] == 2);

	CMyArray<float> numbers2{ 1.2f, 2.4f, 5.5f };
	CHECK(numbers2.Size() == 3);
	CHECK(numbers2[1] == 2.4f);

	CMyArray<string> myArr3{ "chees", "friend" };
	CHECK(myArr3[0] == "chees");
	CHECK(myArr3.Size() == 2);

	cout << "the constructor works correctly" << endl << endl;
}

TEST_CASE("checking the constructor with its array")
{
	cout << "--checking the constructor with its array" << endl;
	CMyArray<int> myArr{ 4, 2, 1 };
	CMyArray<int> myArr2(myArr);

	CHECK(myArr2.Size() == myArr.Size());
	CHECK(myArr2[2] == 1);
	CHECK(myArr2[0] == 4);
	CHECK(myArr2[1] == 2);

	CMyArray<float> numbers{ 1.2f, 2.4f };
	CMyArray<float> numbers3(numbers);
	CHECK(numbers3.Size() == numbers.Size());
	CHECK(numbers3[0] == numbers[0]);

	CMyArray<string> stringArr{ "hello", "world" };
	CMyArray<string> stringArr2(stringArr);
	CHECK(stringArr.Size() == stringArr2.Size());
	CHECK(stringArr[0] == stringArr2[0]);

	cout << "the constructor works correctly" << endl << endl;
}

TEST_CASE("check the method to return the iterator to the beginning and end")
{
	cout << "--check the method to return the iterator to the beginning and end" << endl;
	CMyArray<int> myArr{ 2, 4, 6 };
	CMyIterator<int> it = myArr.Begin();
	CHECK(it.GetValue() == 2);
	it = myArr.End();
	CHECK(it.GetValue() == 6);

	CMyArray<float> numbers{ 2.4f, 5.4f, 1.2f };
	CMyIterator<float> it2 = numbers.Begin();
	CHECK(it2.GetValue() == 2.4f);
	it2 = numbers.End();
	CHECK(it2.GetValue() == 1.2f);

	CMyArray<string> stringArr{ "hello", "world" };
	CMyIterator<string> stringIt = stringArr.Begin();
	CHECK(stringIt.GetValue() == "hello");
	stringIt = stringArr.End();
	CHECK(stringIt.GetValue() == "world");

	cout << "method works correctly" << endl << endl;
}

TEST_CASE("move constructor test")
{
	cout << "--move constructor test" << endl;
	CMyArray<int> myArr{ 4, 2, 1 };
	CMyArray<int> myArr2(move(myArr));

	CHECK(myArr2[2] == 1);
	CHECK(myArr2[0] == 4);
	CHECK(myArr2[1] == 2);
	CHECK(myArr2.Size() == 3);
	CHECK(myArr.Size() == 0);
	CMyIterator<int> it = myArr.Begin();
	CHECK(it == nullptr);
	it = myArr.End();
	CHECK(it == nullptr);

	CMyArray<float> floatArr{ 1.2f, 2.2f };
	CMyArray<float> floatArr2(move(floatArr));
	CHECK(floatArr2.Size() == 2);
	CHECK(floatArr2[0] == 1.2f);
	CHECK(floatArr.Size() == 0);
	CHECK(floatArr.Begin() == nullptr);
	CHECK(floatArr.End() == nullptr);

	CMyArray<string> stringArr{ "hello", "world" };
	CMyArray<string> stringArr2(move(stringArr));
	CHECK(stringArr2.Size() == 2);
	CHECK(stringArr2[0] == "hello");
	CHECK(stringArr.Size() == 0);
	CHECK(stringArr.Begin() == nullptr);
	CHECK(stringArr.End() == nullptr);

	cout << "the constructor works correctly" << endl << endl;
}

TEST_CASE("check the method of appending to the end of the array")
{
	cout << "--check the method of appending to the end of the array" << endl;
	CMyArray<int> myArr{ 4, 3, 5 };
	myArr.PushToEnd(8);
	CHECK(myArr[2] == 5);
	CHECK(myArr[3] == 8);
	CHECK(myArr.Size() == 4);

	CMyArray<float> floatArr{ 4.1f, 3.2f, 5.4f };
	floatArr.PushToEnd(8.2f);
	CHECK(floatArr[2] == 5.4f);
	CHECK(floatArr[3] == 8.2f);
	CHECK(floatArr.Size() == 4);

	CMyArray<string> stringArr{ "hello", "world", "my" };
	stringArr.PushToEnd("friend");
	CHECK(stringArr[2] == "my");
	CHECK(stringArr[3] == "friend");
	CHECK(stringArr.Size() == 4);

	cout << "the method worked correctly" << endl << endl;
}

TEST_CASE("checking that the index operator throws an exception")
{
	cout << "--checking that the index operator throws an exception" << endl;
	string error;
	CMyArray<int> myArr{ 1, 2, 4 };
	try
	{
		myArr[5] == 4;
	}
	catch (const std::exception& err)
	{
		error = err.what();
	}

	CHECK(error == "out of range");
	cout << "the correct exception was thrown out" << endl << endl;
}

TEST_CASE("check that the RBEgin method returns an iterator on the last element")
{
	cout << "--check that the RBEgin method returns an iterator on the last element" << endl;
	CMyArray<int> myArr{ 1, 2, 4, 5 };
	CReverseIt<int> it = myArr.RBegin();
	CHECK(it.GetValue() == 5);
	it++;
	CHECK(it.GetValue() == 4);

	CMyArray<float> floatArr{ 1.2f, 2.3f, 4.1f, 5.4f };
	CReverseIt<float> floatIt = floatArr.RBegin();
	CHECK(floatIt.GetValue() == 5.4f);
	floatIt++;
	CHECK(floatIt.GetValue() == 4.1f);

	CMyArray<string> stringArr{ "hello", "world", "my", "friend" };
	CReverseIt<string> stringIt = stringArr.RBegin();
	CHECK(stringIt.GetValue() == "friend");
	stringIt++;
	CHECK(stringIt.GetValue() == "my");

	cout << "returnable iterator" << endl << endl;
}

TEST_CASE("check that the REnd method returns an iterator on the last element")
{
	cout << "--check that the RBEgin method returns an iterator on the last element" << endl;
	CMyArray<int> myArr{ 1, 2, 4, 5 };
	CReverseIt<int> it = myArr.REnd();
	CHECK(it.GetValue() == 1);
	it--;
	CHECK(it.GetValue() == 2);

	CMyArray<float> floatArr{ 1.2f, 2.3f, 4.1f, 5.4f };
	CReverseIt<float> floatIt = floatArr.REnd();
	CHECK(floatIt.GetValue() == 1.2f);
	floatIt--;
	CHECK(floatIt.GetValue() == 2.3f);

	CMyArray<string> stringArr{ "hello", "world", "my", "friend" };
	CReverseIt<string> stringIt = stringArr.REnd();
	CHECK(stringIt.GetValue() == "hello");
	stringIt--;
	CHECK(stringIt.GetValue() == "world");

	cout << "returnable iterator" << endl << endl;
}

TEST_CASE("checking the method of cleaning the array")
{
	cout << "--checking the method of cleaning the array" << endl;
	CMyArray<int> myArr{ 1, 2, 4, 5 };
	myArr.Clear();
	CHECK(myArr.Size() == 0);
	CHECK(myArr.Begin() == nullptr);
	CHECK(myArr.End() == nullptr);

	CMyArray<float> floatArr{ 1.2f, 2.5f, 4.1f, 5.5f };
	floatArr.Clear();
	CHECK(floatArr.Size() == 0);
	CHECK(floatArr.Begin() == nullptr);
	CHECK(floatArr.End() == nullptr);

	CMyArray<string> stringArr{ "hello", "my", "dear", "friend" };
	stringArr.Clear();
	CHECK(stringArr.Size() == 0);
	CHECK(stringArr.Begin() == nullptr);
	CHECK(stringArr.End() == nullptr);

	cout << "array cleared" << endl << endl;
}

TEST_CASE()
{
	cout << "--verification of the assignment operator" << endl;
	CMyArray<int> arr;
	CMyArray<int> arr2{ 2, 4, 1 };
	arr = arr2;
	CHECK(arr[0] == 2);
	CHECK(arr.Size() == arr2.Size());

	CMyArray<float> floatArr;
	CMyArray<float> floatArr2{ 2.1f, 4.4f, 1.1f };
	floatArr = floatArr2;
	CHECK(floatArr[0] == 2.1f);
	CHECK(floatArr.Size() == floatArr2.Size());

	CMyArray<string> stringArr;
	CMyArray<string> stringArr2{ "hello", "my", "friend" };
	stringArr = stringArr2;
	CHECK(stringArr[0] == "hello");
	CHECK(stringArr.Size() == stringArr2.Size());

	cout << "the assignment was successful" << endl << endl;
}

TEST_CASE()
{
	cout << "--checking the relocation assignment operator" << endl;
	CMyArray<int> arr;
	CMyArray<int> arr2{ 2, 4, 1 };
	arr = move(arr2);
	CHECK(arr[0] == 2);
	CHECK(arr.Size() == 3);
	CHECK(arr2.Size() == 0);
	CMyIterator<int> it = arr2.Begin();
	CHECK(it == nullptr);
	it = arr2.End();
	CHECK(it == nullptr);

	CMyArray<float> floatArr{ 1.2f, 2.2f };
	CMyArray<float> floatArr2 = move(floatArr);
	CHECK(floatArr2.Size() == 2);
	CHECK(floatArr2[0] == 1.2f);
	CHECK(floatArr.Size() == 0);
	CHECK(floatArr.Begin() == nullptr);
	CHECK(floatArr.End() == nullptr);

	CMyArray<string> stringArr{ "hello", "world" };
	CMyArray<string> stringArr2 = move(stringArr);
	CHECK(stringArr2.Size() == 2);
	CHECK(stringArr2[0] == "hello");
	CHECK(stringArr.Size() == 0);
	CHECK(stringArr.Begin() == nullptr);
	CHECK(stringArr.End() == nullptr);

	cout << "relocation assignment works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--changing the size of the array to a smaller side" << endl;
	CMyArray<int> arr{ 2, 4, 1 };
	arr.Resize(2);
	CHECK(arr.Size() == 2);
	CHECK(arr[0] == 2);
	CHECK(arr[1] == 4);

	CMyArray<float> floatArr{ 2.1f, 4.5f, 1.1f };
	floatArr.Resize(2);
	CHECK(floatArr.Size() == 2);
	CHECK(floatArr[0] == 2.1f);
	CHECK(floatArr[1] == 4.5f);

	CMyArray<string> stringArr{ "hello", "my", "friend" };
	stringArr.Resize(2);
	CHECK(stringArr.Size() == 2);
	CHECK(stringArr[0] == "hello");
	CHECK(stringArr[1] == "my");

	cout << "the size of the array has changed correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--resize the array" << endl;
	CMyArray<int> arr{ 2, 4, 1 };
	arr.Resize(4);
	CHECK(arr.Size() == 4);
	CHECK(arr[0] == 2);
	CHECK(arr[1] == 4);
	CHECK(arr[2] == 1);
	CHECK(arr[3] == 0);

	CMyArray<float> floatArr{ 2.1f, 4.4f, 1.1f };
	arr.Resize(4);
	CHECK(arr.Size() == 4);
	CHECK(floatArr[0] == 2.1f);
	CHECK(floatArr[1] == 4.4f);
	CHECK(floatArr[2] == 1.1f);

	CMyArray<string> stringArr{ "hello", "my", "friend" };
	stringArr.Resize(4);
	CHECK(stringArr.Size() == 4);
	CHECK(stringArr[0] == "hello");
	CHECK(stringArr[1] == "my");
	CHECK(stringArr[2] == "friend");
	CHECK(stringArr[3] == "");
	cout << "the size of the array has changed correctly" << endl << endl;
}

TEST_CASE()
{
	system("pause");
}





