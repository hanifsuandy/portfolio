//filename: Point2D.h

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "MyTemplates.h"

using namespace std;

class Point2D
{
	friend ostream& operator<< (ostream&, const Point2D&);

	protected:
		int x, y;
		double distFrOrigin;
		void setDistFrOrigin ();

	public:
		Point2D ();
		Point2D (int, int);

		int getX ();
		int getY ();
		double getScalarValue ();

		void setX (int);
		void setY (int);

        Point2D operator- (Point2D);
        bool operator== (Point2D);
};
