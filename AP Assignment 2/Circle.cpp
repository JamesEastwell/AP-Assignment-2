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
void circle::calculateArea() // area = pi *r^2
{
	area = 3.1415 * radius * radius;
}
void circle::calculatePerimeter() // perimeter = pi * diameter
{
	perimeter = 3.1415 * (radius * 2);
}
void circle::calculatePoints() // only two points are taken for a circle, the leftTop and rightBottom
{
	// Storing the values of leftTop in temporary variables which will allow the other points to be worked out
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	//Creating the rightBottom point and passing it in 
	point rightBottom(tempX + radius*2, tempY + radius*2);
	points.push_back(rightBottom);
}
void circle::move(int newX, int newY) // creating circle's own function definitino for move 
{
	point leftTop(newX, newY); // creating new leftTop as it will be moved and used to work out the other point
	points.clear(); // Clearing the other points as they will be replaced
	points.push_back(leftTop); // readding leftTop
	calculatePoints();// recalculating the other point
	// no need to recalculate the area or perimeter as they have not changed
}
void circle::scale(float scaleX, float scaleY) // creating cirlce's own function definition for scale
{
	radius = radius * scaleX; // timesing the radius by the scale factor
	int tempX = points[0].getX(); // storing the leftTop a this will not change
	int tempY = points[0].getY();
	points.clear(); // clearing space for the new points
	point leftTop(tempX, tempY); // creating and adding a new leftTop into points
	points.push_back(leftTop);
	calculatePoints(); // recalculating the points
	calculateArea(); // recalcualting the area
	calculatePerimeter(); // recalculating the perimeter
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
