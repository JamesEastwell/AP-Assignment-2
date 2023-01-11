#include "Shape.h"
#include "Circle.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Circle function bodies
using namespace std;

circle::circle(int newX, int newY, int newR)
{
	point leftTop(newX, newY);
	points.push_back(leftTop); 			// Adding this point onto the points vector to be stored for later use
	radius = newR;// Assigning the radius to the passed in new radius
	calculateArea();// Calculating the area
	calculatePerimeter();// Calculating the perimeter 
	calculatePoints();// Calculating the other points
	isCircular = true; // Setting isCircular to true as it is a circle
}
circle::circle() // default constructor
{
	radius = 0;
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = true;
	points.push_back(leftTop);
}
// Overriding shapes::calculateArea
// area = pi *r^2
void circle::calculateArea() 
{
	area = 3.1415 * radius * radius;
}
// Overriding shapes::calculatePerimeter
// a circles perimeter is calculated by pi * diameter which is radius*2
void circle::calculatePerimeter() 
{
	perimeter = 3.1415 * (radius * 2);
}
// Overriding shapes::calculatePoints
// For circle it will only calculate one point, rightBottom. leftTop is already stored so therefore is not needed to be calculated again
void circle::calculatePoints() 
{
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	
	point rightBottom(tempX + radius*2, tempY + radius*2);
	points.push_back(rightBottom);
}
// Overriding movable::move, 
// this method will create a new leftTop then clear and recalculate the other points based off of that and the radius
void circle::move(int newX, int newY) 
{
	point leftTop(newX, newY); 
	points.clear(); 
	points.push_back(leftTop); 
	calculatePoints();
	// no need to recalculate the area or perimeter as they have not changed
}
// Overriding movable::scale, this method rescales the Circle based on the give scale factors
// this only uses the modifier for X as since it is a cirlce it cannot be modified for both scales and needs to stay symmetrical
void circle::scale(float scaleX, float scaleY) 
{
	radius = radius * scaleX; 
	int tempX = points[0].getX(); // tempX and Y will store leftTop when the other points get cleared
	int tempY = points[0].getY();
	points.clear(); // other points are cleared as they need to be recalculated
	point leftTop(tempX, tempY);
	points.push_back(leftTop);
	calculatePoints(); 
	calculateArea(); 
	calculatePerimeter(); 
}
std:: string circle::toString() // toString functiont that converts details into a string and returns it
{
	string output = " ";
	// uses the to_string to convert the ints and floats into strings that can be stored and returned
	output = "Circle[r=" + to_string(radius) + "]\nPoints[(" + to_string(points[0].getX()) + ", " + to_string(points[0].getY()) + ")(" + to_string(points[1].getX()) + ", " + to_string(points[1].getY()) + ")]\nArea = " + to_string(area) + " Perimeter = " + to_string(perimeter);
	return output;
}
ostream& operator<<(ostream& os, circle& c) // overload operator
{
	// Calling the toString function from the circle and then outputting through os
	os << c.toString();
	return os;
}
