#include "CLineSegment.h"


CLineSegment::CLineSegment(CPoints startPointP, CPoints endPointP)
	: m_startPoint(startPointP), m_endPoint(endPointP)
{

}

CLineSegment::CLineSegment(CPoints startPointP, CPoints endPointP, string colorP)
	: m_startPoint(startPointP), m_endPoint(endPointP), m_color(colorP)
{
}


CLineSegment::~CLineSegment()
{
}

string CLineSegment::GetOutLineColor()const
{
	return m_color;
}

string CLineSegment::ToString()const
{
	return "Line segment";
}

double CLineSegment::GetArea()const
{
	return 0;
}

double CLineSegment::GetPerimeter()const
{
	CPoints vector;
	vector = m_endPoint - m_startPoint;
	return sqrt(vector.x*vector.x + vector.y*vector.y);
}

CPoints CLineSegment::GetStartPoint()const
{
	return m_startPoint;
}

CPoints CLineSegment::GetEndPoint()const
{
	return m_endPoint;
}