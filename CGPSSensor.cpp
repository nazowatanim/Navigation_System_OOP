/*
 * CGPSSensor.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#include<iostream>
#include "CGPSSensor.h"
#include "CWaypoint.h"
using namespace std;

CGPSSensor::CGPSSensor()
{
	// TODO Auto-generated constructor stub
}


/*to take the value from user and tell the current position*/
CWaypoint CGPSSensor::getCurrentPosition()
{
string name="Current position";
double Latitude,Longitude;
cout<<"Enter Latitude"<< endl;
cin>>Latitude;
cout<<"Enter Longitude"<<endl;
cin>>Longitude;
CWaypoint CurrentPos(name,Latitude,Longitude);
return CurrentPos;
}




