// HttpUrlTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../../HttpUrl/HttpUrl/CHttpUrl.h"
#include "../../HttpUrl/HttpUrl/CUrlParsingError.h"

TEST_CASE("Verifying that the error class returns the correct message")
{
	cout << "--Verifying that the error class returns the correct message" << endl << endl;
	CUrlParsingError myError("Class sucessfuly checked");
	cout << myError.GetMessage() << endl;
	cout << endl << endl;
}

TEST_CASE("constructor only with Url")
{
	cout << "--test : constructor only with Url" << endl << endl;
	CHttpUrl myUrl("http://www.google.com/hello/world.txt");
	cout << "class created successfully" << endl << endl << endl;
}

TEST_CASE("Verify that the protocol is properly checked")
{
	cout << "--test : Verify that the protocol is properly checked" << endl << endl;
	CHttpUrl myUrl("http://www.google.com/hello/world.txt");
	CHECK(myUrl.GetProtocol() == HTTP);
	CHttpUrl myUrl2("https://www.google.com/hello/world.txt");
	CHECK(myUrl2.GetProtocol() == HTTPS);
	cout << "protocols are filled successfully" << endl << endl << endl;
}

TEST_CASE("Verifying that when you enter an invalid protocol, the class throws an exception")
{
	string error = "";
	cout << "--Verifying that when you enter an invalid protocol, the class throws an exception" << endl;

	try
	{
		CHttpUrl myUrl("http12://www.google.com/hello/world.txt");
	}
	catch (const CUrlParsingError& myError)
	{
		error = myError.GetMessage();
	}

	CHECK(error == "incorrect protocol");
	cout << "the correct error is thrown" << endl << endl << endl;
}

TEST_CASE("checking that the port is correctly written when typing url")
{
	cout << "--checking that the port is correctly written when typing url" << endl << endl;
	CHttpUrl myUrl("http://www.google.com/hello/world.txt");
	CHECK(myUrl.GetPort() == 80);
	CHttpUrl myUrl2("https://www.google.com/hello/world.txt");
	CHECK(myUrl2.GetPort() == 443);
	cout << "port matches the protocol requirements" << endl << endl << endl;
}

TEST_CASE("Checking that the correct domain is accepted")
{
	cout << "--test : Checking that the correct domain is accepted" << endl << endl;
	CHttpUrl myUrl("https://www.google.com/hello/world.txt");
	CHECK(myUrl.GetDomain() == "www.google.com");
	cout << "domain is correct" << endl << endl << endl;
}

TEST_CASE("check that when you enter an incorrect document name, an exception will be thrown")
{
	cout << "--test: check that when you enter an incorrect document name, an exception will be thrown" << endl << endl;
	string error = "";
	
	try
	{
		CHttpUrl myUrl("https://www.google..com/hello/world.txt");
	}
	catch (const CUrlParsingError& myError)
	{
		error = myError.GetMessage();
	}

	CHECK(error == "incorrect domain");
	cout << "the correct error is thrown" << endl << endl << endl;
}

TEST_CASE("Verifying that the document is correctly written when you type url")
{
	cout << "--test : Verifying that the document is correctly written when you type url" << endl << endl;
	CHttpUrl myUrl("https://www.google.com/hello/world.txt");
	CHECK(myUrl.GetDocument() == "/hello/world.txt");
	CHttpUrl myUrl2("https://www.google.com");
	CHECK(myUrl2.GetDocument() == "");
	cout << "document is correctly" << endl << endl << endl;
}

TEST_CASE("Exception checking for incorrect document data")
{
	cout << "Exception checking for incorrect document data" << endl << endl;
	string error;

	try
	{
		CHttpUrl myUrl2("https://www.google.com/");
	}
	catch (const CUrlParsingError& myError)
	{
		error = myError.GetMessage();
	}

	CHECK(error == "incroccect document");
	error = "";

	try
	{
		CHttpUrl myUrl2("https://www.google.com/\\aef");
	}
	catch (const CUrlParsingError& myError)
	{
		error = myError.GetMessage();
	}

	CHECK(error == "incroccect document");
	cout << "the correct exceptions are thrown" << endl << endl << endl;
}

TEST_CASE("check the constructor, to which all the data being parsed are sent, except for the port")
{
	cout << "--check the constructor, to which all the data being parsed are sent, except for the port" << endl << endl;
	CHttpUrl myUrl2("www.google.com", "/hello/world.txt", HTTP);
	CHECK(myUrl2.GetDocument() == "/hello/world.txt");
	CHECK(myUrl2.GetDomain() == "www.google.com");
	CHECK(myUrl2.GetPort() == 80);
	CHECK(myUrl2.GetProtocol() == HTTP);
	CHECK(myUrl2.GetURL() == "http://www.google.com/hello/world.txt");
	cout << "class was created with successful data" << endl << endl << endl;
}

TEST_CASE("--check the constructor, to which all the data being parsed are sent")
{
	cout << "--check the constructor, to which all the data being parsed are sent" << endl << endl;
	CHttpUrl myUrl2("www.google.com", "/hello/world.txt", HTTP, 80);
	CHECK(myUrl2.GetDocument() == "/hello/world.txt");
	CHECK(myUrl2.GetDomain() == "www.google.com");
	CHECK(myUrl2.GetPort() == 80);
	CHECK(myUrl2.GetProtocol() == HTTP);
	CHECK(myUrl2.GetURL() == "http://www.google.com/hello/world.txt");
	cout << "class was created with successful data" << endl << endl << endl;
}


TEST_CASE("checking for an exception in case of port mismatch and protocol")
{
	cout << "--test : checking for an exception in case of port mismatch and protocol" << endl << endl;
	string error = "";

	try
	{
		CHttpUrl myUrl2("www.google.com", "/hello/world.txt", HTTP, 443);
	}
	catch (const CUrlParsingError& myError)
	{
		error = myError.GetMessage();
	}

	CHECK(error == "port and protocol mismatch");
	error = "";

	try
	{
		CHttpUrl myUrl2("www.google.com", "/hello/world.txt", HTTPS, 80);
	}
	catch (const CUrlParsingError& myError)
	{
		error = myError.GetMessage();
	}

	CHECK(error == "port and protocol mismatch");
	cout << "the exceptions are correct" << endl << endl << endl;
	system("pause");
	system("pause");
}
