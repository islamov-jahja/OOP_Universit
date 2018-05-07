#include "CRectangle.h"

CRectangle::CRectangle(CPoints leftTop, double width, double height)
	:m_leftTop(leftTop), m_leftBottom(leftTop), m_rightBottom(leftTop), m_side1(m_leftTop, m_leftBottom), m_side2(m_leftBottom, m_rightBottom)
{
	CPoints leftBottom = leftTop;
	leftBottom.y = leftTop.y - width;
	m_leftBottom = leftBottom;
	CPoints rightBottom = leftBottom;
	rightBottom.x = leftBottom.x + height;
	m_rightBottom = rightBottom;
	CLineSegment side1(m_leftTop, m_leftBottom);
	m_side1 = side1;
	CLineSegment side2(m_leftBottom, m_rightBottom);
	m_side2 = side2;
}

CRectangle::CRectangle(CPoints leftTop, double width, double height, string outLineColor, string fillColor)
	:m_leftTop(leftTop), m_leftBottom(leftTop), m_rightBottom(leftTop), m_side1(m_leftTop, m_leftBottom), m_side2(m_leftBottom, m_rightBottom),
	m_outLineColor(outLineColor), m_fillColor(fillColor)
{
	CPoints leftBottom = leftTop;
	leftBottom.y = leftTop.y - width;
	m_leftBottom = leftBottom;
	CPoints rightBottom = leftBottom;
	rightBottom.x = leftBottom.x + height;
	m_rightBottom = rightBottom;
	CLineSegment side1(m_leftTop, m_leftBottom);
	m_side1 = side1;
	CLineSegment side2(m_leftBottom, m_rightBottom);
	m_side2 = side2;
}

CRectangle::~CRectangle()
{
}

double CRectangle::GetArea() const
{
	return m_side1.GetPerimeter()*m_side2.GetPerimeter();
}

double CRectangle::GetPerimeter() const
{
	return m_side1.GetPerimeter()*2 + m_side2.GetPerimeter()*2;
}

string CRectangle::ToString() const
{
	return string("Rectangle");
}

string CRectangle::GetOutLineColor() const
{
	return string(m_outLineColor);
}

string CRectangle::GetFillColor() const
{
	return string(m_fillColor);
}

CPoints CRectangle::GetLeftTop() const
{
	return CPoints(m_leftTop);
}

CPoints CRectangle::GetRightBottom() const
{
	return CPoints(m_rightBottom);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
