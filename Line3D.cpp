//filename: Line3D.cpp

#include "Line3D.h"

//		Point3D pt1, pt2;

Line3D::Line3D ()
{
	pt1.setX(0);
	pt1.setY(0);
	pt1.setZ(0);
	pt2.setX(0);
	pt2.setY(0);
	pt2.setZ(0);
	setLength ();
}

Line3D::Line3D (Point3D _pt1, Point3D _pt2)
{
	setPt1 (_pt1);
	setPt2 (_pt2);
	setLength ();
}

ostream& operator<< (ostream &out, const Line3D &line3D)
{
    /*out << right << "["
        << setw (4) << line3D.getX ()
        << setw (0) << ","
        << setw (5) << line3D.getY ()
        << setw (0) << ","
        << setw (5) << line3D.getZ ()
        << setw (0) << "]"
        << setw (0) << "    "
        << left << line3D.getScalarValue ()
        << endl;

        return out;*/
}

Point3D Line3D::getPt1 ()
{
	return pt1;
}

Point3D Line3D::getPt2 ()
{
	return pt2;
}

void Line3D::setPt1 (Point3D _pt1)
{
	pt1 = _pt1;
}

void Line3D::setPt2 (Point3D _pt2)
{
	pt2 = _pt2;
}

void Line3D::setLength ()
{
	int x1 = pt1.getX ();
	int x2 = pt2.getX ();
	int y1 = pt1.getY ();
	int y2 = pt2.getY ();
	int z1 = pt1.getZ ();
	int z2 = pt2.getZ ();

	length = sqrt( ((x1 - x2)*(x1 - x2)) +
                    ((y1 - y2)*(y1 - y2)) +
                    ((z1 - z2)*(z1 - z2)) );
}

Line3D Line3D::operator- (Line3D line)
{
    Line3D temp;
    temp.pt1 = pt1 - line.pt1;
    temp.pt2 = pt2 - line.pt2;

    return temp;
}

bool Line3D::operator== (Line3D line)
{
    if (pt1 == line.pt1 && pt2 == line.pt2)
        return true;
    else
        return false;
}
