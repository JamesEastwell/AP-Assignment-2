#include "Point.h"

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
void point::getX(int& newX) 
{
	newX = x;
}
void point::getY(int& newY)
{
	newY = y;
}
void point::setX(int newX)
{
	x = newX;
}
void point::setY(int newY)
{
	y = newY;
}
