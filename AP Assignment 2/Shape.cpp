//Shape Class
//Fields
//	Area
//	isCircular
//	leftTop
//	perimeter
//	points
//Methods
//	calculateArea
//		Abstract that will be overriden in the child classes
//	calculatePerimeter
//		Abstract that will be overriden in the child classes
//	calculatePoints
//	toString
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Function bodies stored in the shape.cpp
// No function bodies here as they are virtual and will be added in the derived classes
using namespace std;

// Constructor body
shape::shape()
{
	area = 0;
	isCircular = false;
	point leftTop();
	perimeter = 0.0;
	points;
}
// Deconstructor body
shape::~shape()
{
	// Since leftTop is allocated on heap, it will need to be destroyed when code ends
	delete[] leftTop;
}