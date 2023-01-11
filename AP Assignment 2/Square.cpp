#include "Shape.h"
#include "Square.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

square::square(float newX, float newY, float newE)
{
	point leftTop(newX, newY);
	points.push_back(leftTop);
	edge = newE;
	area = calculateArea();
	perimeter = calculatePerimeter();
	calculatePoints();
	isCircular = false;
}
square::square()
{
	edge = 0;
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = false;
	points;
}
float square::calculateArea()
{
	area = edge * edge;
	return area;
}
float square::calculatePerimeter()
{
	perimeter = edge*4;
	return perimeter;
}
void square::calculatePoints()
{
	//Pass in rightTop
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	
	point rightTop(tempX + edge, tempY);
	points.push_back(rightTop);
	//Pass in rightBottom
	point rightBottom(tempX + edge, tempY + edge);
	points.push_back(rightBottom);
	//Pass in leftBottom
	point leftBottom(tempX, tempY + edge);
	points.push_back(leftBottom);
}
void square::move(int newX, int newY)
{
	point leftTop(newX, newY);
	points.clear();
	points.push_back(leftTop);
	calculatePoints();
}
void square::scale(float scaleX, float scaleY)
{
	edge = edge * scaleX;
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	points.clear();
	point leftTop(tempX, tempY);
	points.push_back(leftTop);
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}
string square::toString()
{
	string output = " ";
	output = "Square[e=" + to_string(edge) +"]\nPoints[(" + to_string(points[0].getX()) + ", " + to_string(points[0].getY()) + ")(" + to_string(points[1].getX()) + ", " + to_string(points[1].getY()) + ")(" + to_string(points[2].getX()) + ", " + to_string(points[2].getY()) + ")(" + to_string(points[3].getX()) + ", " + to_string(points[3].getY()) + ")]\nArea = " + to_string(area) + " Perimeter = " + to_string(perimeter);
	return output;
}
ostream& operator<<(ostream& os, square &s)
{
	os << s.toString();
	return os;
}
