/*
 * CPersistenStorage.h
 *
 *  Created on: Nov 29, 2016
 *      Author: nazow
 */

#ifndef CPERSISTENSTORAGE_H_
#define CPERSISTENSTORAGE_H_


	using namespace std;
	#include "CWpDatabase.h"
	#include "CPoiDatabase.h"
	enum MergeMode { MERGE, REPLACE };
	class CPersistentStorage
	{


	    public:
	    /**
	    * Set the name of the media to be used for persistent storage.
	    * The exact interpretation of the name depends on the implementation
	    * of the component.
	    *
	    * @param name the media to be used
	    */
	    virtual void setMediaName(string name) = 0;
	    /**
	    * Write the data to the persistent storage.
	    *
	    * @param waypointDb the data base with way points
	    * @param poiDb the database with points of interest
	    * @return true if the data could be saved successfully
	    */
	    virtual bool writeData (const CWpDatabase& waypointDb,
	    const CPoiDatabase& poiDb) = 0;
	    /**
	    * The mode to be used when reading the data bases (see readData).
	    */
	//  enum MergeMode { MERGE, REPLACE };
	    /**
	    * Fill the databases with the data from persistent storage. If
	    * merge mode is MERGE, the content in the persistent storage
	    * will be merged with any content already existing in the data
	    * bases. If merge mode is REPLACE, already existing content
	    * will be removed before inserting the content from the persistent
	    * storage.
	    *
	    * @param waypointDb the the data base with way points
	    * @param poiDb the database with points of interest
	    * @param mode the merge mode
	    * @return true if the data could be read successfully
	    */
	    virtual bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,
	    MergeMode mode) = 0;

	//public:
	//  CPersistentStorage();
	//
	    virtual ~CPersistentStorage();
	};


#endif /* CPERSISTENSTORAGE_H_ */
