// filename: Assn3.h

#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "Line3D.h"

list<Point2D> p2d;
list<Line2D> l2d;
list<Point3D> p3d;
list<Line3D> l3d;

string filtering = "Point2D";
string sorting = "x-ordinate";
string order = "ASC";

int printMainMenu ();

void optionOne (int&);
int readTextFile (string);
void storeDataFromFile (string);

void optionTwo ();

void optionThree ();
void optionFour ();
void optionFive ();
void optionSix ();
