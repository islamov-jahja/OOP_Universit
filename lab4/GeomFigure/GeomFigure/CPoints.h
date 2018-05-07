#pragma once
class CPoints
{
public:
	CPoints();
	~CPoints();
	bool operator==(CPoints const& other)const;
	CPoints const operator+(CPoints const& other) const;
	CPoints const operator-(CPoints const& other) const;
	bool operator !=(CPoints const& other)const;
	double x;
	double y;
};

