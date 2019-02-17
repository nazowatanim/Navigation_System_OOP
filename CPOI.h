/*
 * CPOI.h
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#ifndef CPOI_H_
#define CPOI_H_

#include<iostream>
#include<string>
#include "CWayPoint.h"
using namespace std;
/*
 * enumeration type for the type of Point Of Interest
 */
enum t_poi
{
    RESTAURANT, SIGHTSEEING, CLUB, NATURE, MALL
};

class CPOI: public CWaypoint
{

public:
    CPOI();

    // ~CPOI();

private:
    t_poi m_type;
    string m_description;
public:

    /**
     * The constructor will be called automatically, whenever an object is created
     */
    CPOI(t_poi type, string name, string description, double latitude,
            double longitude);

    void set(t_poi type, string name, string description, double latitude,
            double longitude);

    //Overload operator for printing

    friend ostream& operator<<(ostream& out, const CPOI& c);
    /**
     * This function will print our class
     */
    void print(int format);

    t_poi getType();
    string getDescription();
};
#endif /* CPOI_H_ */
