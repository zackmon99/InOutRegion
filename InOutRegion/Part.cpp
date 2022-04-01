#include "Part.h"
#include "Point.h"
#include <iostream>

using namespace std;

Part::Part(Point* pts, int size)
{
	this->size = size;
	points = pts;
	lastIndex = 0;
}


Part::Part()
{
	points = new Point[0];
	size = 0;
	lastIndex = 0;
}

Part::Part(int size) {
	points = new Point[size];
	this->size = size;
	lastIndex = 0;
}

Part::~Part()
{ 
	delete[] points;
}




Point* Part::getPoint(int i)
{
	return &points[i];
}


void Part::setPoint(int i, Point* pt)
{
	points[i] = *pt;
}

void Part::addPoint(double x, double y)
{
	points[lastIndex] = Point(x, y);
	lastIndex++;
}

int Part::getSize()
{
	return size;
}

void Part::initPart(int i) {
	points = new Point[i];
	size = i;
}




