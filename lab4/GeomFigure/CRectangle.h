#pragma once
#include "ISolidShape.h"
#include "CPoints.h"
#include "CLineSegment.h"
class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoints leftTop, double width, double height);
	CRectangle(CPoints leftTop, double width, double height, string outLineColor, string fillColor);
	~CRectangle();
	double GetArea()const override;
	double GetPerimeter()const override;
	string ToString()const override;
	string GetOutLineColor()const override;
	string GetFillColor()const override;
	CPoints GetLeftTop()const;
	CPoints GetRightBottom()const;
	double GetWidth()const;
	double GetHeight()const;
private:
	double m_width;
	double m_height;
	CPoints m_leftTop;
	CPoints m_leftBottom;
	CPoints m_rightBottom;
	string m_fillColor;
	string m_outLineColor;
	CLineSegment m_side1;
	CLineSegment m_side2;
};

