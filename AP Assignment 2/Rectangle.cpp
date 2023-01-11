#include "Shape.h"
#include "Rectangle.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

rectangle::rectangle(float newX, float newY, float newH, float newW)
{
	point leftTop(newX, newY);
	points.push_back(leftTop);
	height = newH;
	width = newW;
	area = calculateArea();
	perimeter = calculatePerimeter();
	calculatePoints();
	isCircular = false;
}
rectangle::rectangle()
{
	height = 0;
	width = 0;
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = false;
	points;
}
float rectangle::calculateArea()
{
	area = height * width;
	return area;
}
float rectangle::calculatePerimeter()
{
	perimeter = ((height*2)+(width*2));
	return perimeter;
}
void rectangle::calculatePoints()
{
	//Pass in rightTop
	int tempX = points[0].getX();
	int tempY = points[0].getY();

	point rightTop(tempX + width, tempY);
	points.push_back(rightTop);
	//Pass in rightBottom
	point rightBottom(tempX + width,tempY + height);
	points.push_back(rightBottom);
	//Pass in leftBottom
	point leftBottom(tempX, tempY + height);
	points.push_back(leftBottom);	
}
void rectangle::move(int newX, int newY) 
{
	point leftTop(newX, newY);
	points.clear();
	points.push_back(leftTop);
	calculatePoints();
}
void rectangle::scale(float scaleX, float scaleY) 
{
	height = height * scaleY;
	width = width * scaleX;
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	points.clear();
	point leftTop(tempX, tempY);
	points.push_back(leftTop);
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}
string rectangle::toString()
{
	//Example:
	//Rectangle[h=50,w=200] 
	//Points[(100, 100)(300, 100)(300, 150)(100, 150)]
	//Area = 10000.0 Perimeter = 500.0
	string output = " ";
	output = "Rectangle[h=" + to_string(height) + ", w= " + to_string(width) + "]\nPoints[(" + to_string(points[0].getX()) + ", " + to_string(points[0].getY()) + ")(" + to_string(points[1].getX()) + ", " + to_string(points[1].getY()) + ")(" + to_string(points[2].getX()) + ", " + to_string(points[2].getY()) + ")(" + to_string(points[3].getX()) + ", " + to_string(points[3].getY()) + ")]\nArea = " + to_string(area) + " Perimeter = " + to_string(perimeter);
	return output;
}
ostream& operator<<(ostream& os, rectangle& r)
{
	os << r.toString();
	return os;
}

