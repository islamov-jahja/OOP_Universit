#pragma once
#include "ISolidShape.h"
#include "CPoints.h"
const double PI = 3.1415926535897932384626433832795;
class CCirlce : public ISolidShape
{
public:
	CCirlce(double radius, CPoints center);
	CCirlce(double radius, CPoints center, string outLineColor, string fillColor);
	~CCirlce();
	double GetArea()const override;
	double GetPerimeter()const override;
	string ToString()const override;
	string GetOutLineColor()const override;
	string GetFillColor()const override;
	CPoints GetCenter()const;
	double GetRadius()const;
private:
	CPoints m_center;
	double m_radius;
	string m_fillColor;
	string m_outLineColor;
};

