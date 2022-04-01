#pragma once
#include "Point.h"
class Part
{
private:
	Point* points;
	int size;
	int lastIndex;
public:
	Part(Point*, int);
	Part();
	Part(int);
	~Part();
	Point* getPoint(int i);
	void setPoint(int i, Point* pt);
	void addPoint(double, double);
	int getSize();
	void initPart(int);
};

