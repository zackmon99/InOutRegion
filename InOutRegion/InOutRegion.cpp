// InOutRegion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "shapefil.h"
#include "Point.h"
#include "Part.h"
#include "Shape.h"

using namespace std;

bool containsPoint(Shape*, double, double);

int main(int argc, char* argv[])
{
	
	printf("Shapefile is %s\n", argv[1]);

	SHPHandle hSHP = SHPOpen(argv[1], "rb");
	if (hSHP == NULL)
	{
		printf("Unable to open:%s\n", argv[1]);
		exit(1);
	}

	Shape* shape = new Shape(&hSHP);

	double latitude = 45.008603;
	double longitude = 50.283444;
	
	bool isContained = containsPoint(shape, longitude, latitude);
	
	if (isContained) {
		cout << "Point ("<< latitude << ", " << longitude << ") is within shape" << endl;
	}
	else {
		cout << "Point (" << latitude << ", " << longitude << ") is outside shape" << endl;
	}
	delete shape;
	exit;
}

bool containsPoint(Shape* shape, double x0, double y0) {

	int a = 0;

	// for each part
	for (int i = 0; i < shape->getSize(); i++)
	{
		double x1 = shape->getPart(i)->getPoint(0)->getX() - x0;
		double y1 = shape->getPart(i)->getPoint(0)->getY() - y0;

		// for each point in part, starting at index 1
		for (int j = 1; j < shape->getPart(i)->getSize(); j++)
		{
			double x2 = shape->getPart(i)->getPoint(j)->getX() - x0;
			double y2 = shape->getPart(i)->getPoint(j)->getY() - y0;

			if ((y2 >= 0) != (y1 >= 0)) {
				double isl = x1 * y2 - y1 * x2;
				if (y2 > y1) {
					if (isl > 0.0) {
						a--;
					}
				
				}
				else {
					if (isl < 0.0) {
						a++;
					}
				}
			}
			x1 = x2;
			y1 = y2;
		}
	}


	return (a != 0);
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
