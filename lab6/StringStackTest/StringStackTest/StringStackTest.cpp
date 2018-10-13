// StringStackTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../../catch/catch.hpp"
#include "../../CStringStack/CStringStack/CStringStack.h"

TEST_CASE("")
{
	cout << "--test bracelet constructor" << endl;
	CStringStack stack{ "hello", "world" };
	stack.Size() == 2;
	stack.Top() == "word";
	cout << "the constructor works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--copy constructor" << endl;
	CStringStack stack{ "hello", "world" };
	CStringStack stack2(stack);
	CHECK(stack2.Size() == stack.Size());
	CHECK(stack.Top() == stack2.Top());
	cout << "the constructor works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--relocating constructor" << endl;
	CStringStack stack{ "hello", "world" };
	CStringStack stack2(move(stack));
	CHECK(stack2.Size() == 2);
	CHECK(stack2.Top() == "world");
	CHECK(stack.Size() == 0);
	cout << "the constructor works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--test method of Push" << endl;
	CStringStack stack;
	stack.Push("hello");
	CHECK(stack.Size() == 1);
	CHECK(stack.Top() == "hello");
	cout << "method works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--test method of Pop" << endl;
	CStringStack stack{ "hello", "world" };
	CHECK(stack.Top() == "world");
	CHECK(stack.Size() == 2);
	stack.Pop();
	CHECK(stack.Size() == 1);
	CHECK(stack.Top() == "hello");

	cout << "method works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "--checking that the correct exception is thrown when trying to pop out from an empty stack" << endl;
	string error;
	try
	{
		CStringStack stack;
		stack.Pop();
	}
	catch (const std::exception& err)
	{
		error = err.what();
	}

	CHECK(error == "stack empty");

	cout << "exception is true" << endl << endl;
}

TEST_CASE()
{
	cout << "--checking that the correct exception is thrown when trying to pop out from an empty stack" << endl;
	string error;
	try
	{
		CStringStack stack;
		stack.Top();
	}
	catch (const std::exception& err)
	{
		error = err.what();
	}

	CHECK(error == "stack empty");

	cout << "exception is true" << endl << endl;
}

TEST_CASE()
{
	cout << "verification of the assignment operator" << endl;
	CStringStack stack1{ "hello", "world" };
	CStringStack stack2 = stack1;
	CHECK(stack1.Size() == stack2.Size());
	CHECK(stack1.Top() == stack2.Top());
	cout << "operator works correctly" << endl << endl;
}

TEST_CASE()
{
	cout << "checking the relocation assignment operator" << endl;
	CStringStack stack1{ "hello", "world" };
	CStringStack stack2 = move(stack1);
	CHECK(stack2.Size() == 2);
	CHECK(stack2.Top() == "world");
	CHECK(stack1.Size() == 0);
	cout << "operator works correctly" << endl << endl;
}

TEST_CASE()
{
	system("pause");
}
