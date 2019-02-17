/*
 * CFileStore.h
 *
 *  Created on: Nov 29, 2016
 *      Author: nazow
 */

#ifndef CFILESTORE_H_
#define CFILESTORE_H_

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include<map>
#include<ctype.h>
#include "CPersistentStorage.h"
#include "CWaypoint.h"
#define WPFields 3
#define POIFields 5
using namespace std;
class CFileStore: public CPersistentStorage
{
public:
    CFileStore();

    void setMediaName(string name);

    bool writeData (const CWpDatabase& waypointDb,
        const CPoiDatabase& poiDb);

    bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode);

    virtual ~CFileStore();

private:
    string file_name;
};

#endif /* CFILESTORE_H_ */
