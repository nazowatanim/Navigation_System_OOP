#include "CRoute.h"
#include "CWaypoint.h"

//Destructor
CRoute::~CRoute()
{

}

//To provide a link to the database of POI
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB)
{
if(pPoiDB==NULL)
{
    cout<<"Connection to Database Failed"<<endl;
}
else
{
    m_pPoiDb = pPoiDB;
}

}

//To provide a link to the database of Waypoint
void CRoute::connectToWpDatabase(CWpDatabase* pWpDB)
{

    if(pWpDB==NULL)
    {
        cout<<"Connection to database failed"<<endl;
    }
    else
    {
    m_pWaypointDb = pWpDB;
    }

}

//To Add waypoints when creating route
void CRoute::addWaypoint(string name)
{

    //Check if the Waypoint Database is empty
    if (m_pWaypointDb != NULL)
    {

        /*
         * Check if the waypoint given is present in the database
         */
        if (m_pWaypointDb->getPointerToWaypoint(name) == NULL)
        {
            cout << "ERROR!Could not find Waypoint " << name
                    << " not in the pool" << endl << endl;
        }
        else
        {
            /*
             * Adds the waypoint
             */
            m_route_vector.push_back(m_pWaypointDb->getPointerToWaypoint(name));

        }

    }
    else
        cout << "Waypoint Database is empty" << endl;

}

//To add Point of Interests when creating route
void CRoute::addPoi(string namePoi, string afterWp)
{

    //CWaypoint* lwp = NULL;
    int k = 0;

    /*
     * Check if POI Database is empty
     */
    if (m_pPoiDb != NULL)
    {
        /*
         * Condition to check if the entered POI was present in the database
         * If not present gives error
         */
        if (m_pPoiDb->getPointerToPoi(namePoi) == NULL)
            cout << "ERROR!Could not find POI " << namePoi << " not in the pool"
                    << endl << endl;

        /*
         * else if present adds the POI to the route
         */
        else
        {

            if(m_pWaypointDb!=NULL)
            {


            CWaypoint *ltest = NULL;
            string lname;

            lname = m_pWaypointDb->getPointerToWaypoint(afterWp)->getName();

            string x;
            /*
             * Reverse iterator is used so that POI is added after the last AfterWp .
             */

            for (rit = m_route_vector.rbegin(); rit != m_route_vector.rend();
                    ++rit)
            {

                x = (*rit)->getName();
                if (afterWp == x)
                {

                    m_route_vector.insert(rit.base(),
                            m_pPoiDb->getPointerToPoi(namePoi));
                    k = k + 1;
                    break;
                }

                else
                {
                    lname = afterWp;

                }

            }
            if (k == 0)
            {

                cout << "The Waypoint " << lname << " is not added" << endl;

            }

        }
        }



    }
    else
        cout << "POI Database is empty" << endl;

}

/*
 * Get the distance of nearest POI
 */
double CRoute::getDistanceNextPoi(CWaypoint const &wp, string name)
{
    CPOI* l_poi;
    CPOI* postn;
    CWaypoint wp1=wp;
    CWaypoint* l_wp;
    double l_lat, l_long;
    double wp_lat,wp_long;
    double dist;
    double minval = HIGH_VAL;
    wp_lat=wp1.getLatitude();
    wp_long=wp1.getLongitude();
    cout << "The Route has following Waypoints and POI's" << endl;

    for (i = m_route_vector.begin(); i != m_route_vector.end(); i++)
    {
        /*
         * Dynamic casting is used to know exactly which type of object
         * is present in the route and to print it accordingly.
         */
        l_poi = dynamic_cast<CPOI*>(*i);
        l_wp = dynamic_cast<CWaypoint*>(*i);

        if (l_poi != NULL)
        {
            l_lat = (*l_poi).getLatitude();
            l_long = (*l_poi).getLongitude();

            dist = R
                    * acos(
                            sin(l_lat * (PI / 180))
                                    * sin(wp_lat * (PI / 180))
                                    + cos(l_lat * (PI / 180))
                                            * cos(wp_lat * (PI / 180))
                                            * cos(
                                                    (wp_long - l_long)
                                                            * (PI / 180)));
            if (minval > dist)
            {
                minval = dist;
                postn = l_poi;
            }
        }

    }cout << "The nearest distance POI is "<<minval<<"" << endl;
    (*postn).print(1);
return minval;
}
/*
 * Operator Overloading
 */
void CRoute::operator +=(string name)
{
    int i = 0;
    if (m_pWaypointDb != NULL)
    {
        if (m_pWaypointDb->getPointerToWaypoint(name) != NULL)
        {
            addWaypoint(name);
            i++;
        }

        if (m_pPoiDb != NULL)
        {
            if (m_pPoiDb->getPointerToPoi(name) != NULL)
            {
                m_route_vector.push_back(m_pPoiDb->getPointerToPoi(name));
                i++;
            }
        }
        else
        {
            cout << "POI Database is empty" << endl;
        }

    }
    else
    {
        cout << "Waypoint Database is empty" << endl;
    }

    if (i == 0)
    {
        cout << "Invalid name" << endl;
    }

}

/*
 * Operator Overloaded
 */
CRoute& CRoute::operator =(const CRoute& origin)
{
    m_pPoiDb = origin.m_pPoiDb;
    m_pWaypointDb = origin.m_pWaypointDb;
    m_route_vector = origin.m_route_vector;
    i = origin.i;

    return *this;
}

/*
 * Operator Overloaded
 */
CRoute operator+(const CRoute &c1, const CRoute &c2)
{
    CRoute res, local_route_1, local_route_2;

    local_route_1 = c1;
    local_route_2 = c2;
    if ((local_route_1.m_pPoiDb == local_route_2.m_pPoiDb)
            && (local_route_1.m_pWaypointDb == local_route_2.m_pWaypointDb))
    {
        local_route_1.m_route_vector.insert(local_route_1.m_route_vector.end(),
                local_route_2.m_route_vector.begin(),
                local_route_2.m_route_vector.end());

    }
    else
    {
        cout << "Routes are not connected to the same database" << endl;
        local_route_1.m_route_vector.clear();
    }
    return local_route_1;
}

//To Print the Waypoints and Point of Interests

void CRoute::print()
{

    CPOI* l_poi;
    CWaypoint* l_wp;
    cout << "The Route has following Waypoints and POI's" << endl;

    for (i = m_route_vector.begin(); i != m_route_vector.end(); i++)
    {
        /*
         * Dynamic casting is used to know exactly which type of object
         * is present in the route and to print it accordingly.
         */
        l_poi = dynamic_cast<CPOI*>(*i);
        l_wp = dynamic_cast<CWaypoint*>(*i);
        if (l_poi != NULL)
        {
            cout << *l_poi << endl;
        }
        else
        {
            cout << *l_wp << endl;
        }

        /*
         * This is a simple print statement
         */
        //(*i)->print(1);
        /*
         * This doesnt work because typecasting is not involved hence both waypoints and POI's are
         * printed in the same way.
         */
        //cout<<(**i)<<endl;
    }

}
CRoute::CRoute()
{
    m_pWaypointDb=NULL;
    m_pPoiDb=NULL;


}
