/*
 * CPoiDatabase.h
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_
using namespace std;
#include<string>
#include<iostream>
#include "CPOI.h"
#include "CWaypoint.h"
#include<map>


class CPoiDatabase: public CPOI
{
public:

    /**
     * The constructor will be called automatically, whenever an object is created
     */

    CPoiDatabase();

    /*
     * This function is used to add POI to the Database
     */

    /*
     * This function is used to get the pointer to POI having the given name
     */

    CPOI* getPointerToPoi(string name);



    void addPoi(CPOI const& poi);
    /*
     * Prints the map data
     */
    void print();
    map<string, CPOI> getMap(); //POI name as key and POI as value
    //map for saving the database
    private:
    map<string, CPOI> m_POI;
    /*
     * Iterator for map
     */
     map<string,CPOI>:: iterator i;


};
#endif /* CPOIDATABASE_H_ */
