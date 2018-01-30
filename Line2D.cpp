//filename: Line2D.cpp

#include "Line2D.h"

Line2D::Line2D ()
{
	pt1.setX(0);
	pt1.setY(0);
	pt2.setX(0);
	pt2.setY(0);
	setLength ();
}

Line2D::Line2D (Point2D _pt1, Point2D _pt2)
{
	setPt1 (_pt1);
	setPt2 (_pt2);
	setLength ();
}

ostream& operator<< (ostream &out, const Line2D &line2D)
{
    /*out << right << "["
        << setw (4) << line2D.getX ()
        << setw (0) << ","
        << setw (5) << line2D.getY ()
        << setw (0) << "]"
        << setw (0) << "    "
        << left << line2D.getScalarValue ()
        << endl;

        return out;*/
}

Point2D Line2D::getPt1 ()
{
	return pt1;
}

Point2D Line2D::getPt2 ()
{
	return pt2;
}

double Line2D::getScalarValue ()
{
	return length;
}

void Line2D::setPt1 (Point2D _pt1)
{
	pt1 = _pt1;
}

void Line2D::setPt2 (Point2D _pt2)
{
	pt2 = _pt2;
}

void Line2D::setLength ()
{
	int x1 = pt1.getX ();
	int x2 = pt2.getX ();
	int y1 = pt1.getY ();
	int y2 = pt2.getY ();

	length = sqrt( ((x1 - x2)*(x1 - x2)) +
			((y1 - y2)*(y1 - y2)) );
}

Line2D Line2D::operator- (Line2D line)
{
    Line2D temp;
    temp.pt1 = pt1 - line.pt1;
    temp.pt2 = pt2 - line.pt2;

    return temp;
}

bool Line2D::operator== (Line2D line)
{
    if (pt1 == line.pt1 && pt2 == line.pt2)
        return true;
    else
        return false;
}
