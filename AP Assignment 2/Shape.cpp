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
#include "Point.h"

using namespace std;

shape::shape()
{
	area = 0;
	isCircular = false;
	leftTop(0,0);
	perimeter = 0.0;
	points;
}
