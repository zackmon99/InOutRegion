#pragma once
#include "Part.h"
#include "shapefil.h"

class Shape
{
private:
	Part* parts;
	int size;
	int lastIndex;
public:
	Shape(Part*, int);
	~Shape();
	Shape(SHPHandle *);
	Part* getPart(int);
	int getSize();
};

