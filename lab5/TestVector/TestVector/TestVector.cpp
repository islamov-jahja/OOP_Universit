// TestVector.cpp: определяет точку входа для консольного приложения.
//
#include "../../../catch/catch.hpp"
#include "stdafx.h"
#include <sstream>
#include "../../Vector/Vector/CVector3DFunctions.h"

CVector3D myVector(1, 2, 3);
CVector3D myVector2(2, 2, 2);
CVector3D myVector3(3, 3, 3);

TEST_CASE("bin plus vectors")
{
	cout << "bin plus vectors" << endl;
	myVector = myVector2 + myVector3;
	CVector3D checkVector(5, 5, 5);
	CHECK(myVector == checkVector);
}

TEST_CASE("bin minus vectors")
{
	cout << "bin minus vectors" << endl;
	myVector = myVector2 - myVector3;
	CVector3D checkVector(-1, -1, -1);
	CHECK(myVector == checkVector);
}

TEST_CASE("un minus")
{
	cout << "un minus" << endl;
	myVector = -myVector2;
	CVector3D checkVector(-2, -2, -2);
	CHECK(myVector == checkVector);
}

TEST_CASE("un plus")
{
	cout << "un plus" << endl;
	myVector = +myVector;
	CHECK(myVector == myVector);
}

TEST_CASE("multiplication and division of a vector by a scalar")
{
	cout << "multiplication and division of a vector by a scalar" << endl;
	myVector2 = myVector2 * 5;
	CVector3D checkVector(10, 10, 10);
	CHECK(myVector2 == checkVector);
	myVector2 = 2 * myVector2;
	CHECK(myVector2 == CVector3D(20, 20, 20));
	myVector2 /= 2;
	myVector2 *= 2;
	checkVector.x = 20; checkVector.y = 20; checkVector.z = 20;
	CHECK(myVector2 == checkVector);
	myVector2 /= 2;
	checkVector.x = 10; checkVector.y = 10; checkVector.z = 10;
	CHECK(myVector2 == checkVector);
	checkVector.x = 14;
	CHECK(myVector2 != checkVector);
	myVector2 = myVector2 / 2;
	checkVector.x = 5; checkVector.y = 5; checkVector.z = 5;
	CHECK(myVector2 == checkVector);
}

TEST_CASE("CHECH += and -=")
{
	cout << "CHECH += and -=";
	CVector3D checkVector(4, 5, 6);
	checkVector += checkVector;
	CHECK(checkVector == CVector3D(8, 10, 12));
	checkVector -= checkVector;
	CHECK(checkVector == CVector3D(0, 0, 0));
}

TEST_CASE("Get length of vector")
{
	cout << "Get length of vector" << endl;
	CVector3D checkLength(3, 4, 0);
	CHECK(checkLength.GetLength() == 5);
}

TEST_CASE("normalize vector")
{
	cout << "normalize vector" << endl;
	CVector3D checkVector5(0, 3, 4);
	CVector3D check2(0, 0.6, 0.8);
	checkVector5.Normalize();
	CHECK(checkVector5 == check2);
}

TEST_CASE("test functions")
{
	cout << "test functions" << endl;
	CVector3D checkVector5(0, 3, 4);
	CVector3D checkVector5Copy(0, 3, 4);
	CVector3D check2(0, 0.6, 0.8);
	checkVector5 = Normalize(checkVector5);
	CHECK(checkVector5 == check2);
	double scalarMultVectors;
	scalarMultVectors = DotProduct(checkVector5, checkVector5Copy);
	CHECK(scalarMultVectors == 5);
	CVector3D checksVectors(2, 2, 2);
	CVector3D checksVectors2(1, 2, 2);
	check2 = CrossProduct(checksVectors, checksVectors2);
	CHECK(check2 == CVector3D(0, -2, 2));
}

TEST_CASE("test >>")
{
	cout << "test >>" << endl;
	string str = "1,2,3";
	CVector3D v(2, 2, 2);
	stringstream myStream(str);
	myStream >> v;
	CHECK(v == CVector3D(1, 2, 3));
	system("pause");
}
