// filename: Assn3.cpp

#include "Assn3.h"

int main ()
{
	int choice, noOfRecords = 0;

	do
	{
		choice = printMainMenu ();

		switch (choice)
		{
			case 1: optionOne (noOfRecords);
				break;
			case 2: optionTwo ();
				break;
			case 3: optionThree ();
				break;
			case 4: optionFour ();
				break;
			case 5: optionFive ();
				break;
			case 6: optionSix ();
				break;
		}
	} while (choice != 7);
}

int printMainMenu ()
{
	cout << "Student ID   : 5841707" << endl
	     << "Student Name : Mohammad Hanif Bin Suandy" << endl
	     << "----------------------------------------" << endl;

	cout << "Welcome to Mission Plan program!" << endl << endl;

	cout << "1)\tRead in data" << endl
	     << "2)\tSpecify filtering criteria (current : " << filtering << ")" << endl
	     << "3)\tSpecify sorting criteria (current : " << sorting << ")" << endl
	     << "4)\tSpecify sorting order (current : " << order << ")" << endl
	     << "5)\tView data" << endl
	     << "6)\tStore data" << endl
	     << "7)\tQuit" << endl << endl;

	cout << "Please enter your choice : ";
	int choice;

	cin >> choice;
	cin.ignore (100, '\n');

	cout << endl;

	return (choice);
}

void optionOne (int &noOfRecords)
{
    string filename;
    cout << "Please enter filename : ";
    getline (cin, filename);

    noOfRecords = readTextFile (filename);

    cout << endl << noOfRecords << " record(s) read in successfully!"
         << endl << endl
         << "Going back to main menu ..." << endl
         << "-------------------------------------------------------" << endl;

    p2d.unique ();
    l2d.unique ();
    p3d.unique ();
    l3d.unique ();
}

int readTextFile (string filename)
{
	string tempString;
	int records = 0;

	fstream infile (filename.c_str(), ios::in);

	if (infile.is_open ())
	{
		while (infile.good ())
		{
			getline (infile, tempString);
			if (tempString == "")
				break;
			storeDataFromFile (tempString);
			records++;
		}
	}
	else
		cout << "Unable to open '" << filename << "'" << endl;

	infile.close ();

	return records;
}

void storeDataFromFile (string tempString)
{
	string str = tempString;
	string name, data, bracket, ws;
	stringstream stream (str);

	getline (stream, name, ','); // class name
	if (name.compare("Point2D") == 0)
    {
        Point2D point2D;

        getline (stream, bracket, '['); // square bracket '['
        getline (stream, data, ','); // x
        int _x = atoi (data.c_str()); // convert string to char to int
        point2D.setX (_x);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ']'); // y
        int _y = atoi (data.c_str()); // convert string to char to int
        point2D.setY (_y);

        p2d.push_back (point2D); // push into list
    }

	if (name.compare("Line2D") == 0)
    {
        Point2D point2D;
        Line2D line2D;

        getline (stream, bracket, '['); // square bracket '['
        getline (stream, data, ','); // x1
        int x1 = atoi (data.c_str()); // convert string to char to int
        point2D.setX (x1);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ','); // y1
        int y1 = atoi (data.c_str()); // convert string to char to int
        point2D.setY (y1);

        line2D.setPt1 (point2D); // set pt1

        getline (stream, bracket, '['); // square bracket '['
        getline (stream, data, ','); // x2
        int x2 = atoi (data.c_str()); // convert string to char to int
        point2D.setX (x2);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ','); // y2
        int y2 = atoi (data.c_str()); // convert string to char to int
        point2D.setY (y2);

        line2D.setPt2 (point2D); // set pt2

        l2d.push_back (line2D); // push into list
    }

	if (name.compare("Point3D") == 0)
    {
        Point3D point3D;

        getline (stream, bracket, '['); // square bracket '['
        getline (stream, data, ','); // x
        int _x = atoi (data.c_str()); // convert string to char to int
        point3D.setX (_x);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ','); // y
        int _y = atoi (data.c_str()); // convert string to char to int
        point3D.setY (_y);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ']'); // z
        int _z = atoi (data.c_str()); // convert string to char to int
        point3D.setZ (_z);

        p3d.push_back (point3D); // push into list
    }

	if (name.compare("Line3D") == 0)
    {
        Point3D point3D;
        Line3D line3D;

        getline (stream, bracket, '['); // square bracket '['
        getline (stream, data, ','); // x1
        int x1 = atoi (data.c_str()); // convert string to char to int
        point3D.setX (x1);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ','); // y1
        int y1 = atoi (data.c_str()); // convert string to char to int
        point3D.setY (y1);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ']'); // z1
        int z1 = atoi (data.c_str()); // convert string to char to int
        point3D.setZ (z1);

        line3D.setPt1 (point3D); // set pt1

        getline (stream, bracket, '['); // square bracket '['
        getline (stream, data, ','); // x2
        int x2 = atoi (data.c_str()); // convert string to char to int
        point3D.setX (x2);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ','); // y2
        int y2 = atoi (data.c_str()); // convert string to char to int
        point3D.setY (y2);

        getline (stream, ws, ' '); // whitespace
        getline (stream, data, ']'); // z2
        int z2 = atoi (data.c_str()); // convert string to char to int
        point3D.setZ (z2);

        line3D.setPt2 (point3D); // set pt2

        l3d.push_back (line3D); // push into list
    }

	/*{
		if (col == 0)
		{
            users[i].loginID = data;
		}
		else if (col == 1)
            {
                users[i].pw = data;
            }
            else if (col == 2)
                {
                    users[i].admin = atoi (data.c_str ());
                }
		col++; //next column data
	}*/
}

void optionTwo ()
{
    char criteria;

    do
    {
        cout << "[ Specifying filtering criteria (current : " << filtering << ") ]"
             << endl << endl
             << "\ta)\tPoint2D records" << endl
             << "\tb)\tPoint3D records" << endl
             << "\tc)\tLine2D records" << endl
             << "\td)\tLine3D records" << endl << endl
             << "Please enter your criteria (a-d) : ";
        cin >> criteria;
    } while (criteria != 'a' ||
             criteria != 'b' ||
             criteria != 'c' ||
             criteria != 'd');

    if (criteria == 'a')
        filtering.assign ("Point2D");
    if (criteria == 'b')
        filtering.assign ("Point3D");
    if (criteria == 'c')
        filtering.assign ("Line2D");
    if (criteria == 'd')
        filtering.assign ("Line3D");

    cout << "Filter criteria successfully set to '" << filtering << "'!"
         << endl << endl
         << "Going back to main menu ..." << endl
         << "-------------------------------------------------------" << endl;
}

void optionThree ()
{
    char criteria;

// filter Point2D
    if (filtering.compare("Point2D") == 0)
    {
        do
        {
            cout << "[ Specifying sorting criteria (current : " << sorting << ") ]"
                 << endl << endl
                 << "\ta)\tX ordinate value" << endl
                 << "\tb)\tY ordinate value" << endl
                 << "\tc)\tDist. Fr Origin value" << endl << endl
                 << "Please enter your criteria (a-c) : ";
            cin >> criteria;
        } while (criteria > 'c');

        if (criteria == 'a')
            sorting.assign ("x-ordinate");
        if (criteria == 'b')
            sorting.assign ("y-ordinate");
        if (criteria == 'c')
            sorting.assign ("dist fr origin");
    }

// filter Point3D
    if (filtering.compare("Point3D") == 0)
    {
        do
        {
            cout << "[ Specifying sorting criteria (current : " << sorting << ") ]"
                 << endl << endl
                 << "\ta)\tX ordinate value" << endl
                 << "\tb)\tY ordinate value" << endl
                 << "\tb)\tZ ordinate value" << endl
                 << "\td)\tDist. Fr Origin value" << endl << endl
                 << "Please enter your criteria (a-d) : ";
            cin >> criteria;
        } while (criteria > 'd');

        if (criteria == 'a')
            sorting.assign ("x-ordinate");
        if (criteria == 'b')
            sorting.assign ("y-ordinate");
        if (criteria == 'c')
            sorting.assign ("z-ordinate");
        if (criteria == 'd')
            sorting.assign ("dist fr origin");
    }

// filter Line2D
    if (filtering.compare("Line2D") == 0)
    {
        do
        {
            cout << "[ Specifying sorting criteria (current : " << sorting << ") ]"
                 << endl << endl
                 << "\ta)\tPt. 1's (x, y) values" << endl
                 << "\tb)\tPt. 2's (x, y) values" << endl
                 << "\tc)\tLength value" << endl << endl
                 << "Please enter your criteria (a-c) : ";
            cin >> criteria;
        } while (criteria > 'c');

        if (criteria == 'a')
            sorting.assign ("Pt. 1");
        if (criteria == 'b')
            sorting.assign ("Pt. 2");
        if (criteria == 'c')
            sorting.assign ("Length");
    }

// filter Line3D
    if (filtering.compare("Line3D") == 0)
    {
        do
        {
            cout << "[ Specifying sorting criteria (current : " << sorting << ") ]"
                 << endl << endl
                 << "\ta)\tPt. 1's (x, y, z) values" << endl
                 << "\tb)\tPt. 2's (x, y, z) values" << endl
                 << "\tc)\tLength value" << endl << endl
                 << "Please enter your criteria (a-c) : ";
            cin >> criteria;
        } while (criteria > 'c');

        if (criteria == 'a')
            sorting.assign ("Pt. 1");
        if (criteria == 'b')
            sorting.assign ("Pt. 2");
        if (criteria == 'c')
            sorting.assign ("Length");
    }

    cout << "Sorting criteria successfully set to '" << sorting << "'!"
         << endl << endl
         << "Going back to main menu ..." << endl
         << "-------------------------------------------------------" << endl;
}

void optionFour ()
{
    char criteria;

    do
    {
        cout << "[ Specifying sorting order (current : " << order << ") ]"
             << endl << endl
             << "\ta)\tASC (Ascending order)" << endl
             << "\tb)\tDSC (Descending order)" << endl << endl
             << "Please enter your criteria (a-b) : ";
        cin >> criteria;
    } while (criteria > 'b');

    if (criteria == 'a')
        order.assign ("ASC");
    if (criteria == 'b')
        order.assign ("DSC");

    cout << "Sorting order successfully set to '" << order << "'!"
         << endl << endl
         << "Going back to main menu ..." << endl
         << "-------------------------------------------------------" << endl;
}

void optionFive ()
{
    list<Point2D> p2dTemp (p2d);
    list<Line2D> l2dTemp (l2d);
    list<Point3D> p3dTemp (p3d);
    list<Line3D> l3dTemp (l3d);

    cout << "[ View data ...  ]" << endl
         << "filtering criteria : " << filtering << endl
         << "sorting criteria : " << sorting << endl
         << "sorting order : " << order << endl << endl;

    while (!p2dTemp.empty())
    {
        cout << p2dTemp.front ();
        p2dTemp.pop_front ();
    }

    while (!l2dTemp.empty())
    {
        cout << l2dTemp.front ();
        l2dTemp.pop_front ();
    }

    while (!p3dTemp.empty())
    {
        cout << p3dTemp.front ();
        p3dTemp.pop_front ();
    }

    while (!p3dTemp.empty())
    {
        cout << p3dTemp.front ();
        p3dTemp.pop_front ();
    }

    cout << "-------------------------------------------------------"
         << endl;
}

void optionSix ()
{

}
