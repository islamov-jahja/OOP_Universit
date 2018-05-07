#pragma once
#include "CPoints.h"
#include "IShape.h"
#include <string>
class CLineSegment : public IShape
{
public:
	CLineSegment(CPoints startPointP, CPoints endPointP);
	CLineSegment(CPoints startPointP, CPoints endPointP, string ColorP);
	~CLineSegment();
	double GetArea()const override;
	double GetPerimeter()const override;
	string ToString()const override;
	string GetOutLineColor()const override;
	CPoints GetStartPoint()const;
	CPoints GetEndPoint()const;
private:
	CPoints m_startPoint;
	CPoints m_endPoint;
	string m_color;
};