/*
 * CRoute.h
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"
#include "CWpDatabase.h"
#include<vector>
#include<math.h>
#define HIGH_VAL 50000


class CRoute
{

private:
    /*
     * Vector to store the pointer to Waypoint objects.
     * It is a common storage container for both CWaypoint and CPOI .
     */

    vector<CWaypoint*> m_route_vector;



private:
    /*
         * Iterator for the vector
         */
    vector<CWaypoint*>::iterator i;

    /*
     * Reverse Iterator for the vector
     */

    vector<CWaypoint*>::reverse_iterator rit;

    /*
         * The database pointer objects are used to provide the connect to database function.
         */
        CWpDatabase* m_pWaypointDb;
        CPoiDatabase * m_pPoiDb;

public:

    CRoute();
    /*
     * This function is used to connect to the POIDatabase
     */

    void connectToPoiDatabase(CPoiDatabase* pPoiDB);

    /*
     * This function is used to add the Waypoints in the route
     */

    void addWaypoint(string name);

    /*
     * This function is used to add the POIs in the route
     */

    void addPoi(string namePoi, string afterWp);

    /*
     * This function is used to print our class
     */

    void print();
    /*
     * Copy constructor
     */
    CRoute& operator=( const CRoute &origin);

    /*
     * This method is used to connect to Waypoint Database
     */

     void connectToWpDatabase(CWpDatabase* pWpDB);

     void operator+=(string name);
     /*
      * Get distance
      */
     double getDistanceNextPoi(CWaypoint const &wp, string name);

    friend CRoute operator+(const CRoute &c1,const CRoute &c2);

//  CRoute operator+(const CRoute &c1,const CRoute &c2);

    /*
     * Destructor
     */

    ~CRoute();

};



#endif /* CROUTE_H_ */

