// TestOfString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../String/String/CMyString.h"
#include <sstream>

TEST_CASE("checking the return function for the length of the string")
{
	cout << "test : checking the return function for the length of the string" << endl;
	CMyString input;
	CHECK(input.GetLength() == 0);
	cout << "test passed successfully" << endl;
}

TEST_CASE("A constructor that initializes a string with a null-terminated string")
{
	cout << "test : constructor that initializes a string with a null-terminated string" << endl;
	CMyString input2("hello world");
	CHECK(input2.GetLength() == strlen("hello world"));
	CHECK(*input2.GetStringData() == 'h');
	string line;

	for (size_t i = 0; i < input2.GetLength(); i++)
		line.push_back(*(input2.GetStringData() + i));

	CHECK(line == "hello world\0");

	CMyString input3("");
	CHECK(input3.GetLength() == strlen(""));
	CHECK(*input3.GetStringData() == '\0');
	cout << "test passed successfully" << endl;
}

TEST_CASE("A constructor initializing a string with data from a character array of a specified length")
{
	cout << "test : constructor initializing a string with data from a character array of a specified length" << endl;
	CMyString input4("hello world", 5);
	CHECK(input4.GetLength() == 5);
	string line;

	for (size_t i = 0; i < input4.GetLength(); i++)
		line.push_back(*(input4.GetStringData() + i));
	
	CHECK(line == "hello");
	CHECK(*(input4.GetStringData() + input4.GetLength()) == '\0');
	string line2;
	CMyString input5("hello world", 100);
	for (size_t i = 0; i < input5.GetLength(); i++)
		line2.push_back(*(input5.GetStringData() + i));

	CHECK(line2 == "hello world");
	CHECK(*(input5.GetStringData() + input5.GetLength()) == '\0');
	cout << "test passed successfully" << endl;
}

TEST_CASE("copy constructor")
{
	cout << "test: copy constructor" << endl;
	CMyString text1("hello world");
	CMyString text2(text1);
	string line;

	for (size_t i = 0; i < text2.GetLength(); i++)
		line.push_back(*(text2.GetStringData() + i));

	CHECK(line == "hello world");
	CHECK(*(text2.GetStringData() + text2.GetLength()) == '\0');
	cout << "test passed successfully" << endl;
}

TEST_CASE("clear function")
{
	cout << "test: clear function" << endl;
	CMyString text1("hello world");
	text1.Clear();
	CHECK(text1.GetLength() == 0);
	CHECK(text1.GetStringData() == nullptr);
	cout << "test passed successfully" << endl;
}

TEST_CASE("relocating constructor")
{
	cout << "relocating constructor" << endl;
	CMyString text1("hello world");
	CMyString text2(move(text1));
	CHECK(text1.GetLength() == 0);
	CHECK(text1.GetStringData() == nullptr);
	string line;
	for (size_t i = 0; i < text2.GetLength(); i++)
		line.push_back(*(text2.GetStringData() + i));
	CHECK(line == "hello world");

	cout << "test passed successfully" << endl;
}

TEST_CASE("a constructor initializing a string with data from a string of the standard C ++ library")
{
	cout << "test: a constructor initializing a string with data from a string of the standard C ++ library" << endl;
	string line = "hello world";
	CMyString text1(line);
	string line2;
	for (size_t i = 0; i < text1.GetLength(); i++)
		line2.push_back(*(text1.GetStringData() + i));

	CHECK(text1.GetLength() == line.length());
	CHECK(line2 == line);
	cout << "test passed successfully" << endl;
}


TEST_CASE("function SubString")
{
	cout << "test: SubString function" << endl;
	CMyString text1("hello world");
	string checkLine;
	for (size_t i = 0; i < 5; i++)
		checkLine.push_back(*(text1.SubString(7, 5).GetStringData() + i));
	CHECK(checkLine == "world\0");
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator ==")
{
	cout << "test : operator ==" << endl;
	CMyString line1("hello world");
	CMyString line2("hello world");
	CHECK(line1 == line2);
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator !=")
{
	cout << "test : operator != " << endl;
	CMyString line1("hello world");
	CMyString line2("hello friend");
	CHECK(line1 != line2);
	cout << "test passed successfully" << endl;
}

TEST_CASE("write to output")
{
	cout << "test : write to output" << endl;
	CMyString sucess("test passed successfully");
	cout << sucess << endl;
}

TEST_CASE("operator =")
{
	cout << "test : operator =" << endl;
	CMyString line1("hello world");
	CMyString line2("zima");
	CHECK(line1 != line2);
	line1 = line2;
	CHECK(line1 == line2);
	line1 = "mimo";
	line1 = line1;
	CHECK(line1 == "mimo");
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator [] for read")
{
	cout << "test : operator [] for read" << endl;
	CMyString line1("hello world");
	CHECK(line1[0] == 'h');
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator [] for write")
{
	cout << "test : operator [] for write" << endl;
	CMyString line1("hello world");
	line1[0] = '4';
	CHECK(line1[0] == '4');
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator += of string")
{
	cout << "test : operator += of string" << endl;
	CMyString lineHello("hello");
	CMyString lineWord(" world");
	lineHello += lineWord;
	CHECK(lineHello == "hello world");
	cout << "test passed successfully" << endl;
}

TEST_CASE("opertator + with other myself string")
{
	cout << "test : opertator + with other string" << endl;
	CMyString lineHello("hello");
	CMyString lineWord(" world");
	CMyString lineHelloWorld;
	lineHelloWorld = lineHello + lineWord;
	CHECK(lineHelloWorld == "hello world");
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator + CMyString with other string")
{
	cout << "test : operator + CMyString with other string" << endl;
	CMyString lineHello("hello");
	string lineWorld = " world";
	CMyString lineHelloWorld;
	lineHelloWorld = lineHello + lineWorld;
	CHECK(lineHelloWorld == "hello world");
	CMyString lineHelloWorld2;
	lineHelloWorld2 = lineWorld + lineHello;
	CHECK(lineHelloWorld2 == " worldhello");
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator + with array of chars")
{
	cout << "test : operator + with array of chars" << endl;
	CMyString lineWorld("world");
	CMyString lineHelloWorld;
	lineHelloWorld = "hello " + lineWorld;
	CHECK(lineHelloWorld == "hello world");
	lineHelloWorld = lineWorld + " hello";
	CHECK(lineHelloWorld == "world hello");
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator > 2 CMyStrings")
{
	cout << "test : operator > 2 CMyStrings" << endl;
	CMyString line1 = "abbbb";
	CMyString line2 = "hell";
	CHECK(line2 > line1);
	line1 = "abcd";
	line2 = "abc";
	CHECK(line1 > line2);
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator < 2 CMyStrings")
{
	cout << "test : operator > 2 CMyStrings" << endl;
	CMyString line1 = "abbbb";
	CMyString line2 = "hell";
	CHECK(line1 < line2);
	line1 = "abcd";
	line2 = "abc";
	CHECK(line2 < line1);
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator >> for CMyString")
{
	cout << "test : operator >> for CMyString" << endl;
	string str = "hello world";
	CMyString line;
	stringstream myStream(str);
	myStream >> line;
	CHECK(line == "hello world");
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator >=")
{
	cout << "test : perator >=" << endl;
	CMyString line("hello");
	CMyString line2("hello");
	CHECK(line >= line2);
	line = "hellop";
	CHECK(line >= line2);
	cout << "test passed successfully" << endl;
}

TEST_CASE("operator <=")
{
	cout << "test : perator <=" << endl;
	CMyString line("hello");
	CMyString line2("hello");
	CHECK(line2 <= line);
	line = "hellop";
	CHECK(line2 <= line);
	cout << "test passed successfully" << endl;
	system("pause");
}