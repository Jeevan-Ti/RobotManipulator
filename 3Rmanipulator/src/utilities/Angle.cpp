#include "Angle.h"

Angle::Angle(double angle, char flag)
{
	if (flag == 'r')
	{
		radiantodegree(angle);
		this->angleRad = angle;
	}
	else
	{
		degreetoradian(angle);
		this->angleDeg = angle;
	}
}

double Angle::rad()
{
	return this->angleRad;
}

void Angle::rad(double update)
{
	this->angleRad = update;
	radiantodegree(update);
}

double Angle::deg()
{
	return this->angleDeg;
}

void Angle::deg(double update)
{
	this->angleDeg = update;
	degreetoradian(update);
}

void Angle::radiantodegree(double& angle)
{
	this->angleDeg = this->angleRad * 57.3240;
}

void Angle::degreetoradian(double& angle)
{
	this->angleRad = this->angleDeg * 0.01744444;
}

Angle::~Angle()
{
}