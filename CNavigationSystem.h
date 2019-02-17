/*
 * CNavigationSystem.h
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CGPSSensor.h"
#include "CRoute.h"
#include "CWpDatabase.h"
#include<map>
#include "CPoiDatabase.h"
#include "CWaypoint.h"
class CNavigationSystem {
public:

    /**
             * The constructor will be called automatically, whenever an object is created
             */
    CNavigationSystem();

    //used for execution

    void run();
    void operator*();
   // map<string, CPOI> m_POI;
  //  map<string,CWaypoint> m_Wp;
private:
    /*
     * Prints the distance to the nearest POI from Current position
     */
    /*
     * Prints the entered route
     */
    void printRoute();
    /*
     * Function to enter the route
     */
    void enterRoute();

    /*
     * Map Definition for POI database
     */

private:
    /*
     * Objects created
     */

    /**
     * @link aggregationByValue
     */
    CGPSSensor m_GPSSensor;

    /**
     * @link aggregationByValue
     */
   CRoute m_route;
   CRoute c1,c2;

    /**
     * @link aggregationByValue
     */
    CPoiDatabase m_PoiDatabase;
    CWpDatabase m_WpDatabase;
};
#endif /* CNAVIGATIONSYSTEM_H_ */
