#include "Point.h"
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
// Default constructor
point::point()
{
	x = 0;
	y = 0;
}
// Overloaded constructor that takes the x and y coordinates
point::point(int newX, int newY) 
{
	x = newX;
	y = newY;
	return;
}
// Functions to retreive x and y
int point::getX()
{
	return x;
}
int point::getY()
{
	return y;
}
