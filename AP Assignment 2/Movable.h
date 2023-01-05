#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <string.h>
#include <vector>
class movable
{
public:
	virtual void move(int newX, int newY)=0;
	virtual void scale(float scaleX, float scaleY)=0;
};