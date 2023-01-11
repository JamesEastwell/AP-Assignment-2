#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Class definitions for circle
using namespace std;
// Derived from shape and movable to allow it to obtain both member features
class circle : public shape, public movable
{
// all made private as they will not need to be accessed from outside of the shape
private:
	int radius;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	string toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
public:
	circle();
	circle(int newX, int newY, int newR);
	// Overload operator as the original function of the operator cannot handle a custom type/class being passed into it
	friend ostream& operator<<(ostream& os, circle& c);

};