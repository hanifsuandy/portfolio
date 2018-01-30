//filename: Point2D.cpp

#include "Point2D.h"

Point2D::Point2D ()
{
	setX (0);
	setY (0);
	setDistFrOrigin ();
}

	Point2D::Point2D (int _x, int _y)
{
	setX (_x);
	setY (_y);
	setDistFrOrigin ();
}

ostream& operator<< (ostream &out, const Point2D &point2D)
{
    /*out << setw (5) << right << "X" << "Y"
        << setw (0) << "    "
        << left << "Dist. Fr Origin"
        << endl
        << "- - - - - - - - - - - - - - - - - - -"
        << endl*/

    out << right << "["
        << setw (4) << point2D.x
        << setw (0) << ","
        << setw (5) << point2D.y
        << setw (0) << "]"
        << setw (0) << "    "
        << left << point2D.distFrOrigin
        << endl;

        return out;
}

int Point2D::getX ()
{
	return x;
}

int Point2D::getY ()
{
	return y;
}

double Point2D::getScalarValue ()
{
	return distFrOrigin;
}

void Point2D::setX (int _x)
{
	x = _x;
}

void Point2D::setY (int _y)
{
	y = _y;
}

void Point2D::setDistFrOrigin ()
{
	distFrOrigin = sqrt( (x*x) + (y*y) );
}

Point2D Point2D::operator- (Point2D pt)
{
    Point2D temp;
    temp.x = x - pt.x;
    temp.y = y - pt.y;

    return temp;
}

bool Point2D::operator== (Point2D pt)
{
    if (x == pt.x && y == pt.y)
        return true;
    else
        return false;
}
