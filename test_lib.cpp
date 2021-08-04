#include<iostream>
using namespace std;

#include <3Rmanipulator.h>

int main()
{
	R3manipulator manip(6, 15, 8);
	Point target(10, 10, 4);
	manip.getangles(manip, target);
	cout << "a1 = " << manip.TwistAngle1.deg() << endl << "a2 = " << manip.TwistAngle2.deg() << endl << "a3 = " << manip.TwistAngle3.deg();
}
