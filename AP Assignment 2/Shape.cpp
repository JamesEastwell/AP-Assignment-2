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

using namespace std;

shape::shape()
{
	area = 0;
	isCircular = false;
	point leftTop();
	perimeter = 0.0;
	points;
}