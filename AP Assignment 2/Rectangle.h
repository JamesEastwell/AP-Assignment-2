#pragma once
#include"Shape.h"
#include"movable.h"
#include"Point.h"
using namespace std;

class rectangle : public shape, public movable
{
private:
	int height;
	int width;
public:
	float calculateArea(int height, int width);
	float calculatePerimeter(int height, int width);
	point calculatePoints(int x, int y, int h, int w);
	string toString();
	rectangle();
	rectangle (int newX, int newY, int newH, int newW);
};