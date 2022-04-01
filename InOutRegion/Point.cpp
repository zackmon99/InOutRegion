#include "Point.h"
#include <iostream>
using namespace std;
double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}

Point::Point()
{
	x = 0.0;
	y = 0.0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& obj)
{
	x = obj.x;
	y = obj.y;
}

Point::~Point()
{

}
