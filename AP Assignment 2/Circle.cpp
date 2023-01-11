#include "Shape.h"
#include "Circle.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

circle::circle(float newX, float newY, float newR)
{
	point leftTop(newX, newY);
	points.push_back(leftTop);
	radius = newR;
	area = calculateArea();
	perimeter = calculatePerimeter();
	calculatePoints();
	isCircular = true;
}
circle::circle()
{
	radius = 0;
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = true;
	points.push_back(leftTop);
}
float circle::calculateArea()
{
	area = 3.1415 * radius * radius;
	return area;
}
float circle::calculatePerimeter()
{
	perimeter = 3.1415 * (radius * 2);
	return perimeter;
}
void circle::calculatePoints()
{
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	//Pass in rightBottom
	point rightBottom(tempX + radius*2, tempY + radius*2);
	points.push_back(rightBottom);
}
void circle::move(int newX, int newY)
{
	point leftTop(newX, newY);
	points.clear();
	points.push_back(leftTop);
	calculatePoints();
}
void circle::scale(float scaleX, float scaleY)
{
	radius = radius * scaleX;
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	points.clear();
	point leftTop(tempX, tempY);
	points.push_back(leftTop);
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}
std:: string circle::toString()
{
	//Example:
	//Rectangle[h=50,w=200] 
	//Points[(100, 100)(300, 100)(300, 150)(100, 150)]
	//Area = 10000.0 Perimeter = 500.0
	string output = " ";
	output = "Circle[r=" + to_string(radius) + "]\nPoints[(" + to_string(points[0].getX()) + ", " + to_string(points[0].getY()) + ")(" + to_string(points[1].getX()) + ", " + to_string(points[1].getY()) + ")]\nArea = " + to_string(area) + " Perimeter = " + to_string(perimeter);
	return output;
}
ostream& operator<<(ostream& os, circle& c)
{
	os << c.toString();
	return os;
}
