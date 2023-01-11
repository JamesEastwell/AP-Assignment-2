#include "Shape.h"
#include "Rectangle.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// rectangle function bodies

using namespace std;

rectangle::rectangle(int newX, int newY, int newH, int newW)// Overloaded constructor that will take in the x, y, height and width
{
	point leftTop(newX, newY); 			// Creating a leftTop point
	points.push_back(leftTop); 			// Adding this point onto the points vector to be stored for later use
	height = newH;// Assigning the height to the passed in new height
	width = newW;// Assigning the width to the passed in new width
	calculateArea();// Calculating the area
	calculatePerimeter();// Calculating the perimeter 
	calculatePoints();// Calculating the other points
	isCircular = false;// Setting isCircular to false since it is a rectangle
}
rectangle::rectangle() // default constructor
{
	height = 0;
	width = 0;
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = false;
	points;
}
void rectangle::calculateArea()// area is height times width
{
	area = height * width;
}
void rectangle::calculatePerimeter() // perimeter is all sides added together 
{
	perimeter = ((height*2)+(width*2));
}
void rectangle::calculatePoints()
{
	// Storing the values of leftTop in temporary variables which will allow the other points to be worked out
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	// Creating the rightTop point and passing it in
	point rightTop(tempX + width, tempY);
	points.push_back(rightTop);
	//Creating the rightBottom point and passing it in 
	point rightBottom(tempX + width,tempY + height);
	points.push_back(rightBottom);
	//Creating the leftBottom point and passing it in 
	point leftBottom(tempX, tempY + height);
	points.push_back(leftBottom);	
}
void rectangle::move(int newX, int newY) 
{
	point leftTop(newX, newY); // new leftTop created
	points.clear();// clear all points as they will be changed
	points.push_back(leftTop); //  readd leftTop
	calculatePoints(); // recalculate other points
	// no need to recalculate the area or perimeter as they have not changed
}
void rectangle::scale(float scaleX, float scaleY) 
{
	height = height * scaleY; // timesing height by scale factor of y
	width = width * scaleX; // timesing width by scale factor of x
	int tempX = points[0].getX(); // storing leftTop so the other points can be cleared. leftTop used to calculate the others
	int tempY = points[0].getY();
	points.clear(); // clearing all points so new ones can be added
	point leftTop(tempX, tempY); // recreating and readding leftTop to points
	points.push_back(leftTop); 
	calculatePoints(); // recalculating all points
	calculateArea();// recalculating area
	calculatePerimeter(); // recalcalting perimeter
}
string rectangle::toString() // toString fucntion that converst details to string so it can be output
{
	string output = " ";
	// uses the to_string to convert the ints and floats into strings that can be stored and returned
	output = "Rectangle[h=" + to_string(height) + ", w= " + to_string(width) + "]"
		"\nPoints[(" + to_string(points[0].getX()) + ", " + to_string(points[0].getY()) + ")(" + to_string(points[1].getX()) + ", " + to_string(points[1].getY()) + ")(" + to_string(points[2].getX()) + ", " + to_string(points[2].getY()) + ")(" + to_string(points[3].getX()) + ", " + to_string(points[3].getY()) + ")]"
		"\nArea = " + to_string((int)area) + " Perimeter = " + to_string(perimeter);
	return output;
}
ostream& operator<<(ostream& os, rectangle& r)
{
	// Calling the toString function from the rectangle and then outputting through os
	os << r.toString();
	return os;
}

