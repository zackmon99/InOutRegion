#pragma once
class Point
{
private:
	double x = 0.0;
	double y = 0.0;
	int number = 1;
public:
	double getX();
	double getY();
	Point();
	Point(double, double);
	Point(const Point &obj);
	~Point();
};

