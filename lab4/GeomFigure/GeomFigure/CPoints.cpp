#include "stdafx.h"
#include "CPoints.h"


CPoints::CPoints()
{
}


CPoints::~CPoints()
{
}

bool CPoints::operator==(CPoints const& other)const
{
	return (x == other.x) && (y == other.y);
}

bool CPoints::operator!=(CPoints const& other)const
{
	return (x != other.x) || (y != other.y);
}

CPoints const CPoints::operator+(CPoints const& other) const
{
	CPoints myPoint;
	myPoint.x = x + other.x;
	myPoint.y = y + other.y;
	return myPoint;
}

CPoints const CPoints::operator-(CPoints const& other) const
{
	CPoints myPoint;
	myPoint.x = x - other.x;
	myPoint.y = y - other.y;
	return myPoint;
}
