/*
 * CWaypoint.h
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_
using namespace std;

#include<iostream>
#include<string>
#include<stdlib.h>

#define degree 1    //print format degree
#define mmss 2      //print format deg mm ss
#define R 6378      // Radius of Earth
#define PI 3.1415926    //Defines value of PI
#define SHOWADDRESS

class CWaypoint
{
public:

    CWaypoint()
    {
        m_name = "";
        m_latitude = 0;
        m_longitude = 0;
    }
    /**
     * The constructor will be called automatically, whenever an object is created
     */
    CWaypoint(string name, double latitude = 0, double longitude = 0);

    /*
     * To set the name, latitude and longitude
     */
      void set(string name, double latitude, double longitude);

    /**
     * This function will get the name
     */

    string getName();

    /**
     * This function will get the latitude
     */

    double getLatitude();

    /**
     * This function will get the Longitude
     */

    double getLongitude();

    /* virtual implementation for polymorphism so that the
     * derived class can override the base class print function
     */

    virtual void print(int format);

//Operator overloading function
    // Since operator<< is a friend of the CWaypoint class, we can access CWaypoint's members directly.
    friend ostream& operator<<(ostream& out, const CWaypoint& c);


     /* Attributes declared private are accessible within the class and its friend classes.
          */
private:
    double m_longitude;
    double m_latitude;
    string m_name;


    /*
     * To allow the Class CPOI to access the private attributes
     */
    friend class CPOI;
};

#endif /* CWAYPOINT_H_ */
