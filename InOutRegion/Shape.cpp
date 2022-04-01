#include "Shape.h"
#include"shapefil.h"
#include <iostream>

using namespace std;
Shape::Shape(Part* prts, int size)
{
	this->size = size;
	parts = new Part[size];
	lastIndex = 0;

	for (int i = 0; i < size; i++)
	{
		parts[i] = prts[i];
	}
}

Shape::~Shape()
{
	if (parts)
		delete[] parts;
}

Shape::Shape(SHPHandle* hSHP) {
	int nEntities;
	int nShapeType;
	double adfMinBound[4];
	double adfMaxBound[4];
	SHPGetInfo(*hSHP, &nEntities, &nShapeType, adfMinBound, adfMaxBound);

	SHPObject* psShape = SHPReadObject(*hSHP, 0);
	int pointCount = psShape->nVertices;

	int partCount = psShape->nParts;
	parts = new Part[partCount];
	size = partCount;
	lastIndex = 0;

	if (partCount == 1) {
		parts[0].initPart(pointCount);
	}
	else {
		parts[0].initPart(psShape->panPartStart[1]);
		int lastIndex = psShape->panPartStart[1];
		for (int i = 1; i < partCount - 1; i++)
		{
			parts[i].initPart(psShape->panPartStart[i + 1] - lastIndex);
			lastIndex = psShape->panPartStart[i + 1];
		}

		parts[partCount - 1].initPart(pointCount - psShape->panPartStart[partCount - 1]);
	}

	for (int i = 0, iPart = 1, partNum = 0; i < pointCount; i++)
	{

		if (iPart < partCount && psShape->panPartStart[iPart] == i) {
			iPart++;
			partNum++;
		}

		parts[partNum].addPoint(psShape->padfX[i], psShape->padfY[i]);
	}

}

Part* Shape::getPart(int i)
{
	return &parts[i];
}

int Shape::getSize()
{
	return size;
}




