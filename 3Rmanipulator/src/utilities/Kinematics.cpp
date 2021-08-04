#include"Kinematics.h"
#include <math.h>

Kinematics::Kinematics(R3manipulator& manip, Point& target_coordinates)
{
	
	double link_lenght_2, link_lenght_3, link_lenght_1,s,k;
	
	link_lenght_1 = manip.link_length1;
	link_lenght_2 = manip.link_length2;
	link_lenght_3 = manip.link_length3;

	s = sqrt(pow(target_coordinates.x,2) + pow(target_coordinates.y, 2));
	k = target_coordinates.z - link_lenght_1;

	manip.TwistAngle3.rad(acos((s * s + k * k - pow(link_lenght_2, 2) - pow(link_lenght_3, 2)) / (2 * link_lenght_3 * link_lenght_2)));
	manip.TwistAngle2.rad(atan(k / s) - atan((link_lenght_3 * sin(manip.TwistAngle3.rad()) / (link_lenght_2 + (link_lenght_3 * cos(manip.TwistAngle3.rad()))))));
	manip.TwistAngle1.rad(atan(target_coordinates.y / target_coordinates.x));
}

Kinematics::~Kinematics()
{
}