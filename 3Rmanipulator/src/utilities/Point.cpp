#include "Point.h"
#include <math.h>

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point::xyz(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Point::distance(Point& p2)
{
	return sqrt(pow(this->x - p2.x, 2) + pow(this->y - p2.y, 2) + pow(this->z - p2.z, 2) + 1);
}

//for performing offset translation
Point Point::operator | (Point const& offset_point)
{
	Point p;
	p.x = this->x + offset_point.x;
	p.y = this->y + offset_point.y;
	p.z = this->z + offset_point.z;
	return p;
}


Point::~Point()
{
}
