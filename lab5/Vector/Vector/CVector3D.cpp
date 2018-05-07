#include "stdafx.h"
#include "CVector3D.h"
//#include "CVector3DFunctions.h"

CVector3D::CVector3D()
	:x(0), y(0), z(0)
{
}

CVector3D::CVector3D(double x0, double y0, double z0)
	:x(x0), y(y0), z(z0)
{
	m_length = sqrt(x*x + y*y + z*z);
}

double CVector3D::GetLength() const
{
	return sqrt(x*x + y*y + z*z);
}

void CVector3D::Normalize()
{
	x = x / m_length; 
	y = y / m_length;
	z = z / m_length;
	m_length = GetLength();
}

CVector3D const CVector3D::operator+(CVector3D const & other) const
{
	return CVector3D(x + other.x, y + other.y, z + other.z);
}

CVector3D const CVector3D::operator-(CVector3D const & other) const
{
	return CVector3D(x - other.x, y - other.y, z - other.z);
}

CVector3D & CVector3D::operator+=(CVector3D const & other)
{
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	return *this;
}

CVector3D & CVector3D::operator-=(CVector3D const & other)
{
	x = x - other.x;
	y = y - other.y;
	z = z - other.z;
	return *this;
}

CVector3D CVector3D::operator*(double scalar) const
{
	return CVector3D(x*scalar, y*scalar, y*scalar);
}

CVector3D CVector3D::operator/(double scalar) const
{
	if (scalar != 0)
		return CVector3D(x / scalar, y / scalar, z / scalar);
	else
		throw 1;
}

CVector3D CVector3D::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

CVector3D CVector3D::operator/=(double scalar)
{
	if (scalar != 0)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
	}
	else
		throw 1;

	return *this;
}


bool CVector3D::operator==(CVector3D const & other) const
{
	return (abs(x-other.x) <= DBL_EPSILON && abs(y - other.y) <= DBL_EPSILON && abs(z - other.z) <= DBL_EPSILON);
}

bool CVector3D::operator!=(CVector3D const & other) const
{
	return (abs(x - other.x) > DBL_EPSILON || abs(y - other.y) > DBL_EPSILON || abs(z - other.z) > DBL_EPSILON);
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D const CVector3D::operator+() const
{
	return *this;
}

CVector3D const operator*(double scalar, CVector3D const& other)
{
	return CVector3D(scalar*other.x, scalar*other.y, scalar*other.z);
}

std::ostream& operator<<(std::ostream& stream, CVector3D const& other)
{
	stream << other.x << ',' << other.y << ',' << other.z;
	return stream;
}

std::istream& operator>>(std::istream& stream, CVector3D& other)
{
	double x;
	double y;
	double z;
	if ((stream >> x) && (stream.get() == ',') &&  (stream >> y) &&	(stream.get() == ',')	&& (stream >> z))
	{
		CVector3D myVector;
		myVector.x = x;
		myVector.y = y;
		myVector.z = z;
		other = myVector;
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
	}
	return stream;
}

CVector3D::~CVector3D()
{
}
