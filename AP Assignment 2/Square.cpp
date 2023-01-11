#include "Shape.h"
#include "Square.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
#include <iomanip>
// Square function bodies
using namespace std;


square::square(int newX, int newY, int newE) // Overloaded constructor that will take in the x, y and edge
{
	point leftTop(newX, newY); 			// Creating a leftTop point
	points.push_back(leftTop); 			// Adding this point onto the points vector to be stored for later use
	edge = newE;						// Assigning the edge to the passed in new edge
	calculateArea();				// Calculating the area
	calculatePerimeter();	// Calculating the perimeter 
	calculatePoints();					// Calculating the other points
	isCircular = false;					// Setting isCircular to false since it is a square
}
square::square() // Default constructor
{
	edge = 0;
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = false;
	points;
}
void square::calculateArea() // Area of a square is simple calculating by timesing the two sides together
{
	area = edge * edge;
}
void square::calculatePerimeter() // Perimeter is calculated by adding all four edges together
{
	perimeter = edge*4;
}
void square::calculatePoints() // Calculating all the points
{
	// Storing the values of leftTop in temporary variables which will allow the other points to be worked out
	int tempX = points[0].getX();
	int tempY = points[0].getY();
	// Creating the rightTop point and passing it in
	point rightTop(tempX + edge, tempY);
	points.push_back(rightTop);
	//Creating the rightBottom point and passing it in 
	point rightBottom(tempX + edge, tempY + edge);
	points.push_back(rightBottom);
	//Creating the leftBottom point and passing it in 
	point leftBottom(tempX, tempY + edge);
	points.push_back(leftBottom);
}
void square::move(int newX, int newY) // Setting the squares own definition for move
{
	point leftTop(newX, newY);	// reassign the new leftTop
	points.clear(); 			// Clearing all the current points
	points.push_back(leftTop);	// Adding the new leftTop to points again
	calculatePoints();			// Recalculting the points based on the new leftTop
	// no need to recalculate the area or perimeter as they have not changed
}
void square::scale(float scaleX, float scaleY) // Setting the squares own definition for scale
{
	edge = edge * scaleX;			// New edge based on the scale factor
	int tempX = points[0].getX();	//	Setting temp values for leftTop since that will be the only point staying the same
	int tempY = points[0].getY();
	points.clear();					// Clearing the points as the others will be replaced
	point leftTop(tempX, tempY);	// Recreating and readding leftTop, the same as it was before
	points.push_back(leftTop);	
	calculatePoints();				// Recalculating all points
	calculateArea();				// Recalculating area
	calculatePerimeter();			// Recalculating perimeter
}
string square::toString() // toString that allows all info to be stored in a string
{
	string output = " "; // Setting up the string
	// Converting all information into one string using to_string for ints and floats
	output = "Square[e=" + to_string(edge) +"]\nPoints[(" + to_string(points[0].getX()) + ", " + to_string(points[0].getY()) + ")(" + to_string(points[1].getX()) + ", " + to_string(points[1].getY()) + ")(" + to_string(points[2].getX()) + ", " + to_string(points[2].getY()) + ")(" + to_string(points[3].getX()) + ", " + to_string(points[3].getY()) + ")]\nArea = " + to_string((int)area) + " Perimeter = " + to_string(perimeter);
	// Returning the string to then be outputted
	return output;
}
ostream& operator<<(ostream& os, square &s) // Overload operator
{
	// Calling the toString function from the square and then outputting through os
	os << s.toString();
	return os;
}
