//filename: Point3D.h

#include "Line2D.h"

class Point3D : public Point2D
{
	friend ostream& operator<< (ostream&, const Point3D&);

	protected:
		int z;
		void setDistFrOrigin ();

	public:
		Point3D ();
		Point3D (int, int, int);

		int getZ ();

		void setZ (int);

        Point3D operator- (Point3D);
        bool operator== (Point3D);
};
