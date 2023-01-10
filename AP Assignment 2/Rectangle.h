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

class rectangle :  public shape, public movable
{
private:
	float height;
	float width;
public:
	float calculateArea();
	float calculatePerimeter();
	void calculatePoints();
	string toString();
	//create move and scale
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	rectangle();
	rectangle (float newX, float newY, float newH, float newW);
};