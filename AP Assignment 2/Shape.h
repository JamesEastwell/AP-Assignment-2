#pragma once
#include <vector>

class shape
{
private:
	float area;
	bool isCircular;
	point leftTop;
	float perimeter;
	vector <point> points;
public:
	shape();
	virtual float calculateArea();
	virtual float calculatePerimeter();
	virtual point calculatePoints();
	virtual void toString();
};