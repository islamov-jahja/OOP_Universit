#include "CTriangle.h"
#include"stdafx.h"

CTriangle::CTriangle(CPoints vertex1, CPoints vertex2, CPoints vertex3)
	: m_side1(vertex1, vertex2), m_side2(vertex1, vertex3), m_side3(vertex2, vertex3),
	m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3)
{
}

CTriangle::CTriangle(CPoints vertex1, CPoints vertex2, CPoints vertex3, string outLineColor, string fillColor)
	: m_side1(vertex1, vertex2, outLineColor), m_side2(vertex1, vertex3, outLineColor), m_side3(vertex2, vertex3, outLineColor),
	m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_fillColor(fillColor), m_outLineColor(outLineColor)
{
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetArea()const
{
	double semiPerimeter = GetPerimeter() / 2;
	double area = sqrt(semiPerimeter*(semiPerimeter - m_side1.GetPerimeter())*
		(semiPerimeter - m_side2.GetPerimeter())*(semiPerimeter - m_side3.GetPerimeter()));
	return area;
}

double CTriangle::GetPerimeter() const
{
	return m_side1.GetPerimeter() + m_side2.GetPerimeter() + m_side3.GetPerimeter();
}

string CTriangle::ToString() const
{
	return string("Triangle");
}

string CTriangle::GetOutLineColor() const
{
	return string(m_outLineColor);
}

string CTriangle::GetFillColor() const
{
	return string(m_fillColor);
}

CPoints CTriangle::GetVertex1() const
{
	return CPoints(m_vertex1);
}

CPoints CTriangle::GetVertex2() const
{
	return CPoints(m_vertex2);
}

CPoints CTriangle::GetVertex3() const
{
	return CPoints(m_vertex3);
}
