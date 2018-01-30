//filename: Point3D.cpp

#include "Point3D.h"

//		int z;

Point3D::Point3D ()
{
	Point2D::setX (0);
	Point2D::setY (0);
	setZ (0);
	setDistFrOrigin ();
}

Point3D::Point3D (int _x, int _y, int _z)
{
	Point2D::setX (_x);
	Point2D::setY (_y);
	setZ (_z);
	setDistFrOrigin ();
}

ostream& operator<< (ostream &out, const Point3D &point3D)
{
    out << right << "["
        << setw (4) << point3D.x
        << setw (0) << ","
        << setw (5) << point3D.y
        << setw (0) << ","
        << setw (5) << point3D.z
        << setw (0) << "]"
        << setw (0) << "    "
        << left << point3D.distFrOrigin
        << endl;

        return out;
}

int Point3D::getZ ()
{
	return z;
}

void Point3D::setZ (int _z)
{
	z = _z;
}

void Point3D::setDistFrOrigin ()
{
	distFrOrigin = sqrt( (x*x) + (y*y) + (z*z) );
}

Point3D Point3D::operator- (Point3D pt)
{
    Point3D temp;
    temp.x = x - pt.x;
    temp.y = y - pt.y;
    temp.z = z - pt.z;

    return temp;
}

bool Point3D::operator== (Point3D pt)
{
    if (x == pt.x && y == pt.y && z == pt.z)
        return true;
    else
        return false;
}
