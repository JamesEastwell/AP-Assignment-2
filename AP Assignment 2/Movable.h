#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
// Movable class definition
class movable
{
public:
	// Functions all made to be pure virtual to make the class abstract
	virtual void move(int newX, int newY)=0;
	virtual void scale(float scaleX, float scaleY)=0;
};