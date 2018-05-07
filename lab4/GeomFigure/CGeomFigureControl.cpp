#include "CGeomFigureControl.h"



CGeomFigureControl::CGeomFigureControl()
{
}


CGeomFigureControl::~CGeomFigureControl()
{
	for (size_t i = 0; i < figures.size(); i++)
		delete figures[i];
}

void CGeomFigureControl::ExecuteTheCommand(string nameOfFigure)
{
	if (nameOfFigure == "Line")
		AddLineSegment();
	else if (nameOfFigure == "Triangle")
		AddTriangle();
	else if (nameOfFigure == "Rectangle")
		AddRectangle();
	else if (nameOfFigure == "Circle")
		AddCircle();
	else if (nameOfFigure == "Max area")
		FindMaxArea();
	else if (nameOfFigure == "Min perimeter")
		FindMinPerimeter();
}

void CGeomFigureControl::AddLineSegment()
{
	string outLineColor = "";
	CPoints lineStartCoordinates;
	CPoints lineEndCoodinates;
	cout << "Enter the coordinates of the beginning of the line with a space" << endl;
	cin >> lineStartCoordinates.x >> lineStartCoordinates.y;
	cout << "Enter the coordinates of the ending of the line with a space" << endl;
	cin >> lineEndCoodinates.x >> lineEndCoodinates.y;
	ChangeColor("Line", outLineColor);
	figures.push_back(new CLineSegment(lineStartCoordinates, lineEndCoodinates, outLineColor));
	cout << "The line is added to the list" << endl;
}

void CGeomFigureControl::AddRectangle()
{
	CPoints leftTop;
	double width, height;
	string outLineColor = "";
	string fillColor = "";
	cout << "enter the coordinate of the upper left point with a space" << endl;
	cin >> leftTop.x >> leftTop.y;
	cout << "enter the width and height of the rectangle through a space (width height)" << endl;
	cin >> width >> height;
	ChangeColor("Line", outLineColor);
	ChangeColor("Fill", fillColor);
	figures.push_back(new CRectangle(leftTop, width, height, outLineColor, fillColor));
	cout << "The rectangle is added to the list" << endl;
}

void CGeomFigureControl::AddTriangle()
{
	string outLineColor = "";
	string fillColor = "";
	CPoints vertex1, vertex2, vertex3;
	cout << "enter the coordinates of the first vertex of the triangle with a space" << endl;
	cin >> vertex1.x >> vertex1.y;
	cout << "enter the coordinates of the second vertex of the triangle with a space" << endl;
	cin >> vertex2.x >> vertex2.y;
	cout << "enter the coordinates of the third vertex of the triangle with a space" << endl;
	cin >> vertex3.x >> vertex3.y;
	ChangeColor("Line", outLineColor);
	ChangeColor("fill", fillColor);
	figures.push_back(new CTriangle(vertex1, vertex2, vertex3, outLineColor, fillColor));
	cout << "The Triangle is added to the list" << endl;
}

void CGeomFigureControl::AddCircle()
{
	double radius;
	CPoints center;
	string outLineColor = "";
	string fillColor = "";
	cout << "enter the radius of the circle" << endl;
	cin >> radius;
	cout << "enter the coordinates of the center of the circle with a space" << endl;
	cin >> center.x >> center.y;
	ChangeColor("Line", outLineColor);
	ChangeColor("Fill", fillColor);
	figures.push_back(new CCirlce(radius, center, outLineColor, fillColor));
	cout << "The circle is added to the list" << endl;
}
bool CGeomFigureControl::IsColor(string color)
{
	if (color.length() != 6)
		return false;
	for (size_t i = 0; i < color.length(); i++)
		if (!((color[i] >= '0' && color[i] <= '9') || (color[i] >= 'b' && color[i] <= 'f') || (color[i]) >= 'B' && color[i] <= 'F'))
			return false;
	return(true);
}

void CGeomFigureControl::FindMaxArea()
{
	if (figures.empty())
		cout << "empty array" << endl;
	else
	{
		auto shapeWithMaxArea = figures[0];
		for (auto x : figures)
			if (x->GetArea() > shapeWithMaxArea->GetArea())
				shapeWithMaxArea = x;
		cout << "Figure with max area:" << endl << "name: " << shapeWithMaxArea->ToString() << endl << "area: " << shapeWithMaxArea->GetArea()
			<< endl << "perimeter: " << shapeWithMaxArea->GetPerimeter() << endl;
		if (shapeWithMaxArea->GetOutLineColor() != "")
			cout << " Out line color: " << shapeWithMaxArea->GetOutLineColor() << endl;
		else
			cout << endl;
	}
}

void CGeomFigureControl::FindMinPerimeter()
{
	if (figures.empty())
		cout << "empty array" << endl;
	else
	{
		auto shapeWithMinPerimeters = figures[0];
		for (auto x : figures)
			if (x->GetPerimeter() < shapeWithMinPerimeters->GetPerimeter())
				shapeWithMinPerimeters = x;
		cout << "Figure with min perimeter" << endl << "name: " << shapeWithMinPerimeters->ToString() << endl
			<< "area: " << shapeWithMinPerimeters->GetArea() << endl << "perimeter: " << shapeWithMinPerimeters->GetPerimeter() << endl;
		if (shapeWithMinPerimeters->GetOutLineColor() != "")
			cout << " Out line colo: " << shapeWithMinPerimeters->GetOutLineColor() << endl;
		else
			cout << endl;
	}
}

void CGeomFigureControl::ChangeColor(string typeColor, string & color)
{
	bool isColor = false;
	while (!isColor)
	{
		cout << "enter" << typeColor << " color if you want else enter \"no\"" << endl;
		cin >> color;
		isColor = IsColor(color);
		if (color == "no")
		{
			color = "";
			isColor = true;
		}
	}
}
