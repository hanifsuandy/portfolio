//filename: Line2D.h

#include "Point2D.h"

class Line2D
{
	friend ostream& operator<< (ostream&, const Line2D&);

	private:
		Point2D pt1, pt2;

	protected:
		double length;
		void setLength ();

	public:
		Line2D ();
		Line2D (Point2D, Point2D);

		Point2D getPt1 ();
		Point2D getPt2 ();
		double getScalarValue ();

		void setPt1 (Point2D);
		void setPt2 (Point2D);

        Line2D operator- (Line2D);
        bool operator== (Line2D);
};
