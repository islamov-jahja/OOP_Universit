#pragma once
#include <iostream>
using namespace std;
class IShape
{
public:
	IShape();
	virtual ~IShape(){};
	virtual double GetArea()const = 0;
	virtual double GetPerimeter()const = 0;
	virtual string ToString()const = 0;
	virtual string GetOutLineColor()const = 0;
};
