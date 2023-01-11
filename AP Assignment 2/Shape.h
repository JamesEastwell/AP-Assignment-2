#pragma once
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Header file to store the definitions of shape.
// This is the base class for the other shapes(rectangle, square and circle)
// This class is made into an abstract since there is at least one virtual function
class shape
{
// Made protected instead of private so the child classes can also use the following fields and methods
protected:
	float area;
	bool isCircular;
	// Creating an instance of a point to store the leftTop (the only point that will be continuously stored)
	point *leftTop = new point(0,0);
	int perimeter;
	// Creating a vector that will hold the points in all the shapes
	// Need to be a vector as each shape has different number of points
	std::vector <point> points;
	// Following functions made virtual so the derived classes can alter the body of the functions
	virtual void calculateArea()=0;
	virtual void calculatePerimeter()=0;
	virtual void calculatePoints()=0;
	// Function to convert the information stored in the shape, into a string that can then be output
	virtual std::string toString() = 0;

public:
	// Constructor made public so that the shapes can be created
	shape();
	virtual ~shape();
};