/*
 * CNavigationSystem.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#include "CNavigationSystem.h"
#include<map>
//Constructor
CNavigationSystem::CNavigationSystem()

{


}

//for executing

void CNavigationSystem::run()
{

    enterRoute();
    printRoute();
    // this->m_PoiDatabase.print();
     // this


}

//function to enter route
void CNavigationSystem::enterRoute()
{

    m_route.connectToPoiDatabase(&m_PoiDatabase);
    m_route.connectToWpDatabase(&m_WpDatabase);

    /*
     *Test route to Add route
     */
    m_route.addWaypoint("Amsterdam");
    m_route.addWaypoint("Stockholm");
    m_route.addWaypoint("Munich");
    m_route.addWaypoint("BELVAI");

    m_route.addWaypoint("Berlin");
    //m_route.addWaypoint("Munich");
//  m_route.addPoi("MENSA","Munich");
    m_route.addPoi("PIZZA HUT", "Stockholm");

    c1.connectToPoiDatabase(&m_PoiDatabase);
    c1.connectToWpDatabase(&m_WpDatabase);
    c1.addWaypoint("Berlin");
    c1.addPoi("Frankenstein Castle","Berlin");

    c2 = m_route + c1;
    m_route+="ZOO Vivarium";

    CWaypoint wp2("Munich", 48.1333, 11.5667);
    m_route.getDistanceNextPoi(wp2,"Testing");


}

//function to print the route
void CNavigationSystem::printRoute()
{

    m_route.print();
    c2.print();

}

void CNavigationSystem::operator*()
{

    CPOI* loc = this->m_PoiDatabase.getPointerToPoi("PIZZA HUT");
             loc->print(2);

}





