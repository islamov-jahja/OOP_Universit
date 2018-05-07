#pragma once
#include "ISolidShape.h"
#include "CPoints.h"
#include "CLineSegment.h"
class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoints vertex1, CPoints vertex2, CPoints vertex3);
	CTriangle(CPoints vertex1, CPoints vertex2, CPoints vertex3, string outLineColor, string fillColor);
	~CTriangle();
	double GetArea()const override;
	double GetPerimeter()const override;
	string ToString()const override;
	string GetOutLineColor()const override;
	string GetFillColor()const override;
	CPoints GetVertex1()const;
	CPoints GetVertex2()const;
	CPoints GetVertex3()const;
private:
	CPoints m_vertex1;
	CPoints m_vertex2;
	CPoints m_vertex3;
	string m_fillColor;
	string m_outLineColor;
	CLineSegment m_side1;
	CLineSegment m_side2;
	CLineSegment m_side3;
};


