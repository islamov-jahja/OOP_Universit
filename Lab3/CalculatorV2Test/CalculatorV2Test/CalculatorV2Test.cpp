// CalculatorV2Test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../calculator_ver_2/calculator_ver_2/CCalculator.h"
#include "../../calculator_ver_2/calculator_ver_2/CControlCalculator.h"
#include <istream>

CCalculator myCalculator;
CControlCalculator myControl;

TEST_CASE("Creat new variable and check mean of variable")
{
	myCalculator.CreatNewVariable("map");
	CHECK(isnan(myCalculator.GetValueOfVariable("map").second));
	myCalculator.ChangeValueOfIdentifier("map", 3.3);
	CHECK(myCalculator.GetValueOfVariable("map").second == 3.3);
}

TEST_CASE("Creat new variable")
{
	cout << "Creat new variable" << endl;
	int resultOperation;
	resultOperation = myCalculator.CreatNewVariable("x");
	CHECK(resultOperation == 0);
	resultOperation = myCalculator.CreatNewVariable("1X");
	CHECK(resultOperation == 1);
	resultOperation = myCalculator.CreatNewVariable("x");
	CHECK(resultOperation == 2);
}

TEST_CASE("Get Varible In Value")
{
	cout << "Get Variable in value" << endl;
	myCalculator.CreatNewVariable("f");
	CHECK(isnan(myCalculator.GetValueOfVariable("f").second));
}

TEST_CASE("Creat or change variable")
{
	cout << "creat or change variable" << endl;
	int resultOperation;
	resultOperation = myCalculator.CreatNewVariable("y");
	CHECK(resultOperation == 0);
	resultOperation = myCalculator.CreatNewVariable("1X");
	CHECK(resultOperation == 1);
	resultOperation = myCalculator.CreatNewVariable("x");
	CHECK(resultOperation == 2);
	myCalculator.ChangeValueOfIdentifier("x", 5);
	CHECK(myCalculator.GetValueOfVariable("x").second == 5);
}

TEST_CASE("Creat Function and Get value of function")
{
	cout << "creat Function and get value of function" << endl;
	int resultOperation;
	myCalculator.CreatNewVariable("y");
	resultOperation = myCalculator.CreatNewFunction("f1", "y");
	CHECK(resultOperation == 0);
	resultOperation = myCalculator.CreatNewFunction("2f", "y");
	CHECK(resultOperation == 1);
	resultOperation = myCalculator.CreatNewFunction("f", "z");
	CHECK(resultOperation == 2);
	resultOperation = myCalculator.CreatNewFunction("f1", "y");
	myCalculator.ChangeValueOfIdentifier("y", 3.3);
	CHECK(myCalculator.GetValueOfFunction("f1").second == 3.3);
	myCalculator.CreatNewFunction("f2", "f1", '+', "y");
	CHECK(myCalculator.GetValueOfFunction("f2").second == 6.6);
	cout << endl << endl << endl;
}

TEST_CASE("all test")
{
	cout << "Create a variable with the name t" << endl;
	myControl.HandleCommand(string("var t"));
	cout << "checking that the value of the variable created is equal to isnan" << endl;
	myControl.HandleCommand(string("print t"));
	cout << "attempt to create a variable with a previously existing name" << endl;
	myControl.HandleCommand(string("var t"));
	cout << "creating a variable with an incorrect name" << endl;
	myControl.HandleCommand(string("var 1t"));
	myControl.HandleCommand(string("let 1t=5"));
	cout << "assigning a previously declared variable \"t\" to a value of 5" << endl;
	myControl.HandleCommand(string("let t=5"));
	cout << "print the value of the variable t" << endl;
	myControl.HandleCommand(string("print t"));
	cout << "create and initialize a previously undisclosed t2 variable with a value of 10" << endl;
	myControl.HandleCommand(string("let t2=10"));
	cout << "print the value of the variable t2" << endl;
	myControl.HandleCommand(string("print t2"));
	cout << "changes the value of the t2 variable to the value of the previously declared t variable" << endl;
	myControl.HandleCommand(string("let t2=t"));
	cout << "print the value of the variable t2" << endl;
	myControl.HandleCommand(string("print t2"));
	cout << "an attempt to initialize a T2 variable to a variable not previously declared" << endl;
	myControl.HandleCommand(string("let t2=v"));
	cout << "creating a function f whose value is a previously declared variable t" << endl;
	myControl.HandleCommand(string("fn f=t"));
	cout << "print the value of the function f" << endl;
	myControl.HandleCommand(string("print f"));
	cout << "verify that the function value cannot be changed" << endl;
	myControl.HandleCommand(string("let f=t"));
	cout << "attempt to create a function with a previously existing name" << endl;
	myControl.HandleCommand(string("fn f=t"));
	myControl.HandleCommand(string("fn f=t+t2"));
	cout << "check the operation of addition when you create a function f2 whose value will be f+t" << endl;
	myControl.HandleCommand(string("fn f2=f+t"));
	cout << "print the value of the function f2" << endl;
	myControl.HandleCommand(string("print f2"));
	cout << "check the operation of subtraction when you create a function f3 whose value will be f-t" << endl;
	myControl.HandleCommand(string("fn f3=f-t"));
	cout << "print the value of the function f3" << endl;
	myControl.HandleCommand(string("print f3"));
	cout << "checks the division operation when the f4 function is created and its value is f/t" << endl;
	myControl.HandleCommand(string("fn f4=f/t"));
	cout << "print the value of the function f4" << endl;
	myControl.HandleCommand(string("print f4"));
	cout << "checks the multiplication operation when the f5 function is created with the value f*t" << endl;
	myControl.HandleCommand(string("fn f5=f*t"));
	cout << "print the value of the function f5" << endl;
	myControl.HandleCommand(string("print f5"));
	cout << "check that when calculating a function if the value of one variable is not defined, the value of the whole function is undefined" << endl;
	myControl.HandleCommand(string("var z"));
	myControl.HandleCommand(string("fn f6=z+f5"));
	myControl.HandleCommand(string("print f6"));
	cout << "verify that the print function prints the value of a variable t" << endl;
	myControl.HandleCommand(string("print t"));
	cout << "checking that the print function prints the value of the f5 function" << endl;
	myControl.HandleCommand(string("print f5"));
	cout << "check that the print function displays an error when you try to output non-existent ID" << endl;
	myControl.HandleCommand(string("print f9"));
	cout << "checking the printvars function" << endl;
	myControl.HandleCommand(string("printvars"));
	cout << "checking the printfns function" << endl;
	myControl.HandleCommand(string("printfns"));
	cout << "checking function nesting" << endl;
	myControl.HandleCommand(string("var n"));
	myControl.HandleCommand(string("let n=767"));
	myControl.HandleCommand(string("fn e=n"));
	myControl.HandleCommand(string("fn g=e"));
	myControl.HandleCommand(string("fn q=g"));
	myControl.HandleCommand(string("print q"));
	system("pause");
}

/*TEST_CASE("Test class cotrol calculator")
{
	myControl.HandleCommand(string ("let v0=0"));
	myControl.HandleCommand(string("let v1=1"));
	myControl.HandleCommand(string("fn fib0=v0"));
	myControl.HandleCommand(string("fn fib1=v1"));
	myControl.HandleCommand(string("fn fib2=fib1+fib0"));
	myControl.HandleCommand(string("fn fib3=fib2+fib1"));
	myControl.HandleCommand(string("fn fib4=fib3+fib2"));
	myControl.HandleCommand(string("fn fib5=fib4+fib3"));
	myControl.HandleCommand(string("fn fib6=fib5+fib4"));
	myControl.HandleCommand(string("printfns"));
	myControl.HandleCommand(string("printvars"));
	myControl.HandleCommand(string("var v0"));
	system("pause");
}*/