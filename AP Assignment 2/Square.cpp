#include"Shape.h"
#include"Movable.h"
#include"Square.h"

using namespace std;

square::square(int newX, int newY, int newE)
{
	area = calculateArea(newE);
	perimeter = calculatePerimeter(newE);
	point* leftTop = new point(newX, newY);
	calculatePoints(newX, newY, newE);
	isCircular = false;
}
square::square()
{
	area = 0;
	perimeter = 0;
	point leftTop(0, 0);
	isCircular = false;
	points;
}
float square::calculateArea(int edge)
{
	area = edge * edge;
	return area;
}
float square::calculatePerimeter(int edge)
{
	perimeter = edge * 4;
	return perimeter;
}
point square::calculatePoints(int x, int y, int e)
{
	//Pass in rightTop
	point rightTop(x + e, y);
	points.push_back(rightTop);
	//Pass in rightBottom
	point rightBottom(x + e, y + e);
	points.push_back(rightBottom);
	//Pass in leftBottom
	point leftBottom(x, y + e);
	points.push_back(leftBottom);
}
void square::toString()
{

}