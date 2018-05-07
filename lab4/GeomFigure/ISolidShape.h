#pragma once
#include "IShape.h"

class ISolidShape : public IShape
{
public:
	ISolidShape();
	virtual ~ISolidShape() {};
	virtual string GetFillColor() const = 0;
};

