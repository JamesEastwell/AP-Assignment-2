#pragma once
#include <vector>

class shape
{
protected:
	float area;
	bool isCircular;
	point* leftTop = new point();
	float perimeter;
	vector <point> points;
public:
	shape();
	virtual float calculateArea();
	virtual float calculatePerimeter();
	virtual point calculatePoints();
	virtual void toString();
};