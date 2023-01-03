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
	float calculateArea(int newE);
	float calculatePerimeter(int edge);
	point calculatePoints(int x, int y, int e);
	void toString();
	square();
	square(int newX, int newY, int newE);
};