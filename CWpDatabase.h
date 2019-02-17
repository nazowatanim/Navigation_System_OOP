/*
 * CWpDatabase.h
 *
 *  Created on: Nov 25, 2016
 *      Author: nazow
 */

#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_

#include "CWaypoint.h"
#include<map>

/*provides methods to addWaypoint, getPointerToWaypoint and to read and
write the contents of Database to and from to Waypoint  File*/

class CWpDatabase {
public:
	CWpDatabase();

	 //To add Waypoint to the database

	    void addWaypoint(CWaypoint const & wp);

	      /* Gets the pointer to the waypoint in the database
	     */
	    CWaypoint* getPointerToWaypoint(string name);

	    void print();
	    map<string, CWaypoint> getMap();

	private:
	    //map to save values to Waypoint database
	    map<string, CWaypoint> m_Wp;


	};

#endif /* CWPDATABASE_H_ */
