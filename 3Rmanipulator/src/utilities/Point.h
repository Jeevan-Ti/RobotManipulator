#ifndef Point_h
#define Point_h

class Point
{
public:
	double x, y, z;
	Point(double x = 0, double y = 0, double z = 0);
	void xyz(double x, double y, double z);

	double distance(Point& p2);

	Point operator | (Point const& obj);
	
	~Point();

private:

};



#endif // !Point_h
