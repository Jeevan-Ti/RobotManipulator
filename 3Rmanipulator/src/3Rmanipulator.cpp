#include "3Rmanipulator.h"
#include "utilities/Kinematics.h"


R3manipulator::R3manipulator(double link_lenght1, double link_length2, double link_length3)
{
	this->link_length1 = link_lenght1;
	this->link_length2 = link_length2;
	this->link_length3 = link_length3;
	//this->Total_Offset.xyz(0,0,0);
}

void R3manipulator::getangles(R3manipulator& manip, Point& target)
{
	Kinematics k1(manip, target);

}

void R3manipulator::UpdateOffset(Point offset_point)
{
	Total_Offset = Total_Offset | offset_point;
}


R3manipulator::~R3manipulator()
{
}