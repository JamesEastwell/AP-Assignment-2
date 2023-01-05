#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
point::point()
{
	x = 0;
	y = 0;
}
point::point(int newX, int newY) 
{
	x = newX;
	y = newY;
	return;
}
int point::getX()
{
	return x;
}
int point::getY()
{
	return y;
}
void point::setX(int newX)
{
	x = newX;
}
void point::setY(int newY)
{
	y = newY;
}
