#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
class point
{
private:
	int x;
	int y;
public:
	point();
	point(int newX, int newY);
	int getX();
	int getY();
	void setY(int newY);
	void setX(int newX);
};