/*
 * main.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: nazow
 */

#include <iostream>
#include <stdlib.h>
#include "CWaypoint.h"
#include "CNavigationSystem.h"
//#include "CPersistentStorage.h"
//#include "CFileStore.h"
#include "CWpDatabase.h"
#include  "CPoiDatabase.h"

using namespace std;
int main(void)
{

    cout << "Navigation_1 gestarted." << endl << endl;


    //CFileStore file_test1;
    CWpDatabase wp1;
    CPoiDatabase poi1;
/*//
file_test1.setMediaName("CSV_Test");
//file_test1.writeData (wp1,poi1);
file_test1.readData( wp1, poi1,REPLACE);*/


//  CNavigationSystem n1;
//  n1.run();
//  *n1;
    string trial;
    CWaypoint* p1;
    CWaypoint p2("Amsterdam",45,52);
    p1=new CWaypoint(p2);
    p1=new CWaypoint[5];
    //p1[0]=p2;
    cout<<p1[0];
    cout<<*p1;

//  p1 = new CPOI;
//  p1->print(2);
//
//  int myArray [5];
//  int* myBuffer = myArray;
//
//  for (int i = 0; i<5; i++)
//  myArray[i] = i * i;
//  for (int i = 0; i<5; i++)
//  cout << "myArray [" << i << "] at adress " << &myArray[i] << " = "
//  << myArray[i] << endl;
//
//  cout << "Testcase 5 : " << ++*++myBuffer << endl;
    return 0;
}
