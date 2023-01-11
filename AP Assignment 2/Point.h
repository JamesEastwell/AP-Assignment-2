#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Point class definition
class point
{
private:
// Each point will hold x and y so they are stored together
	int x;
	int y;
public:
// Default constructor
	point();
// Overloaded constructor that takes x and y as parameters so the point can be declared
	point(int newX, int newY);
// Get functions for points to retrieve the x and y for each point
	int getX();
	int getY();
};