//filename: Line3D.h

#include "Point3D.h"

class Line3D : public Line2D
{
	friend ostream& operator<< (ostream&, const Line3D&);

	private:
		Point3D pt1, pt2;

	protected:
		void setLength ();

	public:
		Line3D ();
		Line3D (Point3D, Point3D);

		Point3D getPt1 ();
		Point3D getPt2 ();

		void setPt1 (Point3D);
		void setPt2 (Point3D);

        Line3D operator- (Line3D);
        bool operator== (Line3D);
};
