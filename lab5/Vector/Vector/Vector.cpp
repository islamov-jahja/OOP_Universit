// Vector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CVector3DFunctions.h";
#include <iostream>
using namespace std;

/*double DotProduct(CVector3D const& v1, CVector3D const& v2)
{
	CVector3D v3(v1.x*v2.x, v1.y*v2.y, v1.z*v2.z);
	return (v3.x + v3.y + v3.z);
}

CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2)
{
	return CVector3D(((v1.y*v2.z) - (v1.z*v2.y)), (-((v1.x*v2.z) - (v1.z*v2.x))), ((v1.x*v2.y) - (v1.y*v2.x)));
}

CVector3D Normalize(CVector3D const& v)
{
	CVector3D v2;
	v2 = v;
	v2.Normalize();
	return v2;
}*/

int main()
{
	CVector3D myVector(2, 2, 3);
	CVector3D myVector2(3, 4, 1);
	CVector3D myVector3(1, 2, 3);
	cout << myVector2;
	system("pause");
    return 0;
}

