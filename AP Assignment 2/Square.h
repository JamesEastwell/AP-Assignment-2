#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Class definitions for square
using namespace std;

// Derived from shape and movable to allow it to obtain both member features
class square : public shape, public movable
{
// all made private as they will not need to be accessed from outside of the shape
private:
	int edge;
	void calculateArea();
	void calculatePerimeter();
	void calculatePoints();
	string toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
// The functions that will need to be called outside of the shape are therefore made public
public:
	square();
	square(int newX, int newY, int newE);
	friend ostream& operator<<(ostream& os, square &s); // Overload operator
};