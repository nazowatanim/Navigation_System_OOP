/*
 * CWaypoint.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#include<iostream>
#include "CWaypoint.h"
using namespace std;
#include<math.h>

//Method Implementations

//Constructor for class CWaypoint

CWaypoint::CWaypoint(string name, double latitude, double longitude)
{

    m_name = name;
    if (latitude >= -90 && latitude <= 90)
    {
        m_latitude = latitude;
        if (longitude >= -180 && longitude <= 180)//condition for valid longitude
            m_longitude = longitude;

    }

}

//Returns the name
string CWaypoint::getName()
{

    return m_name;

}

//Returns the latitude
double CWaypoint::getLatitude()
{

    return m_latitude;

}

//Returns the longitude
double CWaypoint::getLongitude()
{

    return m_longitude;

}


/*
 * Sets the name latitude and longitude
 */

void CWaypoint::set(string name, double latitude, double longitude)
{
    m_name = name;

    /*
     * Valid range for latitude -90 to +90
     */
    if (latitude >= -90 && latitude <= 90)
        m_latitude = latitude;
    else
        m_latitude = 0;
    /*
     * Valid range for Longitude -180 to +180
     */

    if (longitude >= -180 && longitude <= 180)    //condition for valid longitude
        m_longitude = longitude;
    else
        m_longitude = 0;

}
/*
 * Operator overloading for printing
 */

ostream& operator<<(ostream& out, const CWaypoint& c)
{
    //Local variables
    int deg_lat, mm_lat, deg_long, mm_long;
    double ss_lat, ss_long;

    //Conversion of latitude to deg mm ss
    deg_lat = (int) c.m_latitude;
    mm_lat = (int) ((c.m_latitude - (float) deg_lat) * 60.0);
    ss_lat = (((c.m_latitude - deg_lat) * 3600.0)) - (((float) mm_lat) * 60);

    //Conversion of longitude to deg mm ss

    deg_long = (int) c.m_longitude;
    mm_long = (int) ((c.m_longitude - (float) deg_long) * 60.0);
    ss_long = (((c.m_longitude - deg_long) * 3600.0))
            - (((float) mm_long) * 60);

    //Printing the latitude in deg mm ss format



    out << " " << c.m_name << "  on latitude " << deg_lat << " deg " << mm_lat
            << "min " << ss_lat << "s" ;

    //Printing the longitude in deg mm ss format

    out << " and longitude " << deg_long << " deg "
            << mm_long << "min " << ss_long << "s" << endl<<endl;




    return out;
}

//Method to print the values of latitude, longitude and place name

void CWaypoint::print(int format)
{

    //Prints in Degree

    switch (format)
    {
    case 1:
    {

        cout << "" << m_name << " on latitude " << m_latitude
                << " and longitude " << m_longitude << " " << endl<<endl;

        break;
    }

        //Prints in deg mm ss
    case 2:
    {

    }

    }

}
