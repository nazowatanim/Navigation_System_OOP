/*
 * CPoiDatabase.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#include "CPoiDatabase.h"
#include "CPOI.h"
using namespace std;
#include<string>

//Constructor
CPoiDatabase::CPoiDatabase()
{

    /*
     * Adding the POI's to the database
     */
    CPOI p1(RESTAURANT, "MENSA", "Best Mensa", 10, 20.4);
    CPOI p2(RESTAURANT, "PIZZA HUT", "Delicious Pizza", 48.5, 7.91);
    CPOI p3(SIGHTSEEING, "Neuschwanstein Castle", "Fairytale Castle", 47.5577,
            10.749);
    CPOI p4(SIGHTSEEING, "Frankenstein Castle", "Best Castle", 49.7933, 8.6683);
    CPOI p5(CLUB, "Hochheim", "Club for parties", 20.1, 6.5);
    CPOI p6(CLUB, "Extasis", "Nice Music", 60, 25);
    CPOI p7(NATURE, "Rosenhoehe", "Beautiful Park", 49, 6.2);

    CPOI p8(NATURE, "ZOO Vivarium", "good Zoo but limited variety", 35, 5.2);
    CPOI p9(MALL, "LP12 Mall", "Very good Mall of Berlin with good food court",
            52.51, 13.3798);
    CPOI p10(MALL, "Pasing Arcaden", "Very near to S Bahn station", 48.1486,
            11.4633);

    addPoi(p1);
    addPoi(p2);
    addPoi(p3);
    addPoi(p4);
    addPoi(p6);
    addPoi(p5);
    addPoi(p7);
    addPoi(p8);
    addPoi(p9);
    addPoi(p10);

}

/*
 * Gets the pointer to the required POI in database using the name.
 */
CPOI* CPoiDatabase::getPointerToPoi(string name)

{

    //Local declaration
    CPOI* c1;

     map<string,CPOI>:: iterator i;
    for (i = m_POI.begin(); i != m_POI.end(); i++)
    {

        if (i->first == name) //POI's name
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
 * Adds the POI to the database
 */
void CPoiDatabase::addPoi(CPOI const& poi)
{

    CPOI x;
    x = poi;

    m_POI.insert(pair<string, CPOI>(x.getName(), x));
//  m_POI[x.getName()]=x;

}

void CPoiDatabase::print()

{
     map<string,CPOI>:: iterator i;

    CPOI c1;
    for (i = m_POI.begin(); i != m_POI.end(); i++)
    {
        c1 = i->second; //POI as value
        cout<<c1;
    }


}
/*
 * Method to access the MAP of CPOI data. It returns the Map.
 */

map<string, CPOI> CPoiDatabase::getMap()
{
    return this->m_POI;

}


