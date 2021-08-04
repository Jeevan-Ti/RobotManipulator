#ifndef R3manipulator_h
#define R3manipulator_h

#include "utilities/Point.h"
#include "utilities/Angle.h"

class R3manipulator
{
public:
	R3manipulator(double link_lenght1, double link_length2, double link_length3);
	~R3manipulator();
	
	void getangles(R3manipulator& manip, Point& target);
	Angle TwistAngle1, TwistAngle2, TwistAngle3;
private:
	friend class Kinematics;
	Point Total_Offset, temp;
	//Angle TwistAngle1, TwistAngle2, TwistAngle3;
	double link_length1, link_length2, link_length3;
	void UpdateOffset(Point offset_point);
};


#endif // !R3manipulator_h
