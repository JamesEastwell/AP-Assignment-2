#pragma once

class movable
{
public:
	virtual void move(int newX, int newY);
	virtual void scale(float scaleX, float scaleY);
};