#pragma once
#include"Shape.h"
#include"movable.h"
#include"Point.h"
using namespace std;

class square : public shape, public movable
{
private:
	int edge;
public:
	float calculateArea();
	float calculatePerimeter();
	point calculatePoints();
	void toSring();
	square();
	square(int newX, int newY, int newE);
};