#ifndef Angles_h
#define Angles_h

class Angle
{
public:
	
	Angle(double angle = 0, char flag = 'd');
	~Angle();
	double rad();
	void rad(double update);
	double deg();
	void deg(double update);
private:
	double angleRad;
	double angleDeg;
	void radiantodegree(double& angle);
	void degreetoradian(double& angle);
};



#endif // !Angles_h
