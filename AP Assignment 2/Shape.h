#pragma once
#include "Movable.h"
#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

class shape
{
protected:
	float area;
	bool isCircular;
	point *leftTop = new point(0,0);
	float perimeter;
	std::vector <point> points;

	virtual float calculateArea()=0;
	virtual float calculatePerimeter()=0;
	virtual void calculatePoints()=0;
public:
	shape();
	virtual ~shape();
	virtual std::string toString()=0;
};