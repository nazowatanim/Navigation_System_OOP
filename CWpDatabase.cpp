

#include <iostream>
#include "CWpDatabase.h"
#include "CWaypoint.h"
using namespace std;

CWpDatabase::CWpDatabase()
{

    /*
     * Adding Waypoints to the Waypoint Database.
     */
    CWaypoint wp1("Amsterdam", 52.3667, 4.9);
    CWaypoint wp2("Munich", 48.1333, 11.5667);
    CWaypoint wp3("Berlin", 52.5167, 13.3833);
    CWaypoint wp4("Stockholm", 59.3294, 18.0686);

    addWaypoint(wp1);
    addWaypoint(wp2);
    addWaypoint(wp3);
    addWaypoint(wp4);
}

/*
 * Method to add the waypoint passed as wp to the Waypoint database
 *  using insert operation of map
 */

void CWpDatabase::addWaypoint(CWaypoint const& wp)
{
    CWaypoint wp1;
    wp1 = wp; //As wp is const it cannot be used in insert directly

    m_Wp.insert(pair<string, CWaypoint>(wp1.getName(), wp1));

}

/*
 * Gets the pointer to the waypoint in the waypoint database by using name as key
 */

CWaypoint* CWpDatabase::getPointerToWaypoint(string name)
{

    CWaypoint* c1;

    /*
     * Looping through the map
     */

    map<string, CWaypoint>::iterator i;
    for (i = m_Wp.begin(); i != m_Wp.end(); ++i)
    {

        if (i->first == name)
        {
            c1 = &i->second;
            break;

        }
        else
        {
            c1 = NULL;
        }
    }
    return c1;

}

/*
 * Prints the Waypoints from the Waypoint database.
 */
void CWpDatabase::print()

{
    map<string, CWaypoint>::iterator i;
    CWaypoint c1;
    for (i = m_Wp.begin(); i != m_Wp.end(); ++i)
    {
        c1 = i->second;
        cout<<c1;
    }

}
/*
 * Method to get the map  as its a private attribute.
 */

map<string, CWaypoint> CWpDatabase::getMap()
{

    return this->m_Wp;
}
