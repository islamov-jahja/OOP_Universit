#include "float.h"
#include "math.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CVector3D
{
public:
	CVector3D();
	CVector3D(double x0, double y0, double z0);
	double GetLength()const;
	void Normalize();
	CVector3D const operator+()const;
	CVector3D const operator-()const;
	CVector3D const operator+(CVector3D const& other)const;
	CVector3D const operator-(CVector3D const& other)const;
	CVector3D& operator+=(CVector3D const& other);
	CVector3D& operator-=(CVector3D const& other);
	CVector3D operator*(double scalar)const;
	CVector3D operator/(double scalar)const;
	CVector3D operator*=(double scalar);
	CVector3D operator/=(double scalar);
	bool operator==(CVector3D const& other)const;
	bool operator!=(CVector3D const& other)const;
	~CVector3D();
	double x, y, z;
private:
	double m_length;
};


std::ostream& operator <<(std::ostream& stream, CVector3D const& other);
std::istream& operator >>(istream& stream, CVector3D& other);
CVector3D const operator *(double scalar, CVector3D const& other);