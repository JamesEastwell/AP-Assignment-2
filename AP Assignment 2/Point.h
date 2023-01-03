#pragma once

class point
{
protected:
	int x;
	int y;
public:
	point();
	point(int newX, int newY);
	void getX(int& newX);
	void getY(int& newY);
	void setY(int newY);
	void setX(int newX);
	friend ostream &operator<<(ostream &output, const )
};