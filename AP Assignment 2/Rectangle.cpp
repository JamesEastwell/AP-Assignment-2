#include"Shape.h"
#include"Movable.h"
#include"Rectangle.h"

#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

rectangle::rectangle(int newX, int newY, int newH, int newW)
{
	area = calculateArea(newH, newW);
	perimeter = calculatePerimeter(newH, newW);
	point* leftTop = new point(newX, newY);
	calculatePoints(newX, newY, newH, newW);
	isCircular = false;
}
rectangle::rectangle()
{
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = false;
	points;
}
float rectangle::calculateArea(int height, int width)
{
	area = height * width;
	return area;
}
float rectangle::calculatePerimeter(int height, int width)
{
	perimeter = ((height*2)+(width*2));
	return perimeter;
}
point rectangle::calculatePoints(int x, int y, int h, int w)
{
	//Pass in rightTop
	point rightTop(x + w, y);
	points.push_back(rightTop);
	//Pass in rightBottom
	point rightBottom(x + w, y + h);
	points.push_back(rightBottom);
	//Pass in leftBottom
	point leftBottom(x, y + h);
	points.push_back(leftBottom);
}
void rectangle::toSring()
{
	for (int i; i <= 4; i++)
	{
		cout << points[i]<< endl;
	}
}
ostream& operator << (ostream& output, rectangle& r)
{
	output << r << endl;
	return output;
}