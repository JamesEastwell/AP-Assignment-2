#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

class square : public shape, public movable
{
private:
	float edge;
public:
	float calculateArea(int newE);
	float calculatePerimeter(int edge);
	void calculatePoints(int x, int y, int e);
	string toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	square();
	square(int newX, int newY, int newE);
};