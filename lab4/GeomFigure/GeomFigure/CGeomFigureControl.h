#pragma once
#include "CLineSegment.h"
#include "CPoints.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCirlce.h"
#include "ISolidShape.h"
#include "IShape.h"
#include <vector>

class CGeomFigureControl
{
public:
	CGeomFigureControl();
	~CGeomFigureControl();
	void ExecuteTheCommand(string nameOfFigure);
private:
	void AddLineSegment();
	void AddRectangle();
	void AddTriangle();
	void AddCircle();
	bool IsColor(string color);
	void FindMaxArea();
	void FindMinPerimeter();
	void ChangeColor(string typeColor, string &color);
	vector<IShape*> figures;
};

