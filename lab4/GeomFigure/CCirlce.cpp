#include "CCirlce.h"





CCirlce::CCirlce(double radius, CPoints center)
	: m_radius(radius), m_center(center)
{
}

CCirlce::CCirlce(double radius, CPoints center, string outLineColor, string fillColor)
	: m_radius(radius), m_center(center), m_outLineColor(outLineColor), m_fillColor(fillColor)
{
}

CCirlce::~CCirlce()
{
}

double CCirlce::GetArea() const
{
	return PI * m_radius * m_radius;
}

double CCirlce::GetPerimeter() const
{
	return 2 * PI * m_radius;
}

string CCirlce::ToString() const
{
	return string("Circle");
}

string CCirlce::GetOutLineColor() const
{
	return string(m_outLineColor);
}

string CCirlce::GetFillColor() const
{
	return string(m_fillColor);
}

CPoints CCirlce::GetCenter() const
{
	return CPoints(m_center);
}

double CCirlce::GetRadius() const
{
	return m_radius;
}
