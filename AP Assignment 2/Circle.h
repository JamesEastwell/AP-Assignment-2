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

class circle : public shape, public movable
{
private:
	float radius;
public:
	float calculateArea();
	float calculatePerimeter();
	void calculatePoints();
	string toString();
	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);
	circle();
	circle(float newX, float newY, float newE);
	friend ostream& operator<<(ostream& os, circle& c);

};