/*
 * CFileStore.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: nazow
 */

#include "CFileStore.h"

CFileStore::CFileStore()
{
    // TODO Auto-generated constructor stub

}

void CFileStore::setMediaName(string name)
{

    file_name = name;
}

bool CFileStore::writeData(const CWpDatabase& waypointDb,
        const CPoiDatabase& poiDb)
{

    /*
     * Local Variables for write operation
     */
    CWpDatabase local_wp;
    CPoiDatabase local_poi;
    double local_lat_wp, local_long_wp, local_lat_poi, local_long_poi;
    string local_name_wp, local_name_poi, local_desc;
    t_poi local_type;
    CWaypoint wp1;
    CPOI poi1;
    ofstream file_wp;
    ofstream file_poi;
    char wp_array[25]; //Array for Waypoint file name
    char poi_array[25]; //Array for POI file name
    string wp_name;
    string poi_name;
    map<string, CWaypoint> local_wpMap = local_wp.getMap();
    wp_name = file_name + "-wp.txt";
    poi_name = file_name + "-poi.txt";
    strcpy(wp_array, wp_name.c_str());
    strcpy(poi_array, poi_name.c_str());
    map<string, CPOI> local_poiMap = local_poi.getMap();
    file_wp.open(wp_array, ios::out);
    file_poi.open(poi_array, ios::out);

    /*
     * Iterator for the map for Waypoints
     */
    map<string, CWaypoint>::iterator j;
    /*
     * Loop through the map to write values to the file.
     */

    for (j = local_wpMap.begin(); j != local_wpMap.end(); j++)
    {

        wp1 = j->second;
        local_name_wp = wp1.getName();
        local_lat_wp = wp1.getLatitude();
        local_long_wp = wp1.getLongitude();

        file_wp << local_name_wp << ";" << local_lat_wp << ";" << local_long_wp
                << endl;
    }
    /*
     * Iterator for the map for POI
     */
    map<string, CPOI>::iterator i;

    /*
     * Loop through the map to add POI to the file
     */
    for (i = local_poiMap.begin(); i != local_poiMap.end(); i++)
    {

        poi1 = i->second;
        local_lat_poi = poi1.getLatitude();
        local_long_poi = poi1.getLongitude();
        local_name_poi = poi1.getName();
        local_type = poi1.getType();
        local_desc = poi1.getDescription();
        /*
         * To get the type
         */
        switch (local_type)
        {

        case RESTAURANT:
            file_poi << "RESTAURANT" << ";" << local_name_poi << ";"
                    << local_desc << ";";
            break;

        case SIGHTSEEING:
            file_poi << "SIGHTSEEING" << ";" << local_name_poi << ";"
                    << local_desc << ";";
            break;

        case CLUB:
            file_poi << "CLUB" << ";" << local_name_poi << ";" << local_desc
                    << ";";
            break;

        case NATURE:
            file_poi << "NATURE" << ";" << local_name_poi << ";" << local_desc
                    << ";";
            break;

        case MALL:
            file_poi << "MALL" << ";" << local_name_poi << ";" << local_desc
                    << ";";
            break;

        }

        file_poi << local_lat_poi << ";" << local_long_poi << endl;

    }

    return true;
}

/*
 * Method to read data from file
 */
bool CFileStore::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
        MergeMode mode)
{
    /*
     * Local variables for read operation
     */
    char wp_array[50];
    char poi_array[50];
    string line;
    string wp_name;
    string poi_name;
    wp_name = file_name + "-wp.txt";
    poi_name = file_name + "-poi.txt";
    strcpy(wp_array, wp_name.c_str());
    strcpy(poi_array, poi_name.c_str());
    ifstream file_wp;
    ifstream file_poi;
    char delim = ';';
    CWpDatabase local_wp = waypointDb;
    CPoiDatabase local_poi = poiDb;
    double local_lat_wp, local_long_wp, local_lat_poi, local_long_poi;
    string local_name_wp, local_name_poi, local_desc;
    t_poi local_type;
    CWaypoint wp1;
    CPOI poi1;
    map<string, CWaypoint> local_wpMap = local_wp.getMap();
    map<string, CPOI> local_poiMap = local_poi.getMap();
    bool status = true;
    int count;
    int wp_line_no = 1;
    int poi_line_no = 1;
    string poi_val;
    string wp_val;
    file_wp.open(wp_array, ios::in);

    int k = 0;

    /*
     * If mode is Replace existing data from the database is deleted and new data added.
     */
    if (mode == REPLACE)
    {
        local_wpMap.clear();
    }
    /*
     * Checks if file is open
     */
    if (file_wp.is_open())
    {

        while (!file_wp.eof())

        {
            getline(file_wp, line);
            count = 0;
            if (line.length() != 0)
            {
                string wp_line = line.c_str();
                for (unsigned int i = 0; i < line.length(); i++)
                {
                    if (wp_line[i] == delim)
                        count++;
                }
                /*
                 * If the line contains greater than 2 delimiter then too many fields
                 */
                if (count > 2)
                    cout << "Error !Too many fields in line " << wp_line_no
                            << "" << endl;
                /*
                 * If the line contains less than two delimiters then too few fields
                 */
                else if (count < 2)
                    cout << "Error !Very few fields in line " << wp_line_no
                            << "" << endl;
                /*
                 * If the line contains two delimiters continue read operation
                 */
                else if (count == 2)
                {

                    stringstream s(line);

                    while (getline(s, wp_val, delim))
                    {
                        if (k % WPFields == 0)
                        {
                            local_name_wp = wp_val;
                            k++;
                        }

                        else if (k % WPFields == 1)
                        {
                            int i = 0;
                            /*
                             * Check if the latitude contains any alphabetic characters.If so then display an
                             * error and the line is not added.
                             */
                            while (wp_val[i])
                            {
                                if (isalpha(wp_val[i]))
                                {
                                    status = false;

                                    cout
                                            << "Error!Alphabetic characters not allowed for latitude in line"
                                            << wp_line_no << "" << endl << endl;
                                }
                                i++;
                            }
                            /*
                             * if the data is in German notation(i.e comma instead of decimal point)
                             * replace the comma with decimal point and add to database.
                             */
                            for (unsigned int i = 0; i < wp_val.length(); i++)
                            {
                                if (wp_val[i] == ',')
                                    wp_val[i] = '.';
                            }

                            {

                                local_lat_wp = atof(wp_val.c_str());
                            }
                            k++;

                        }
                        else if (k % WPFields == 2)
                        {

                            int i = 0;
                            while (wp_val[i])
                            {
                                if (isalpha(wp_val[i]))
                                {
                                    status = false;

                                    cout
                                            << "Error:Alphabetic characters not allowed for Longitude in line"
                                            << wp_line_no << "" << endl << endl;
                                }
                                i++;
                            }

                            for (unsigned int i = 0; i < wp_val.length(); i++)
                            {
                                if (wp_val[i] == ',')
                                    wp_val[i] = '.';
                            }

                            local_long_wp = atof(wp_val.c_str());
                            wp1.set(local_name_wp, local_lat_wp, local_long_wp);
                            k++;
                        }

                    }
                    /*
                     * If there are no errors then add the object to the database
                     */

                    if (status == true)
                    {
                        local_wp.addWaypoint(wp1);

                    }

                    status = true;
                }
                /*
                 * Track the line number
                 */
                wp_line_no++;

            }
            else
            {
                ;
            }

        }

        waypointDb = local_wp;
        local_wp.print();
        /*
         * Close the file
         */
        file_wp.close();
    }
    else
    {
        return false;
    }

    file_poi.open(poi_array, ios::in);

    int p = 0;
    bool poi_error = true;
    /*
     * If the mode is replace then delete existing values in database and add the new ones
     */
    if (mode == REPLACE)
        local_poiMap.clear();
    /*
     * Check if file is open
     */
    if (file_poi.is_open())
    {
        /*
         * Check for End Of File
         */
        while (!file_poi.eof())

        {

            getline(file_poi, line);
            count = 0;
            if (line.length() != 0)
            {
                string poi_line = line.c_str();
                /*
                 * Keep a count of delimiters
                 */
                for (unsigned int i = 0; i < line.length(); i++)
                {
                    if (poi_line[i] == delim)
                        count++;
                }
                /*
                 * If the number of delimiters in the line are more than 4 then too many fields in line.
                 */

                if (count > 4)
                    cout << "Error !Too many fields in line " << poi_line_no
                            << "" << endl;

                /*
                 * If the number of delimiters in the line are more than 2 then too few fields in line.
                 */
                else if (count < 4)
                    cout << "Error !Very few fields in line " << poi_line_no
                            << "" << endl;

                /*
                 * If the number of delimiters in the line are equal to four then continue with read operation
                 */
                else if (count == 4)
                {

                    stringstream s(line);

                    while (getline(s, poi_val, delim))
                    {

                        if (p % POIFields == 0)
                        {
                            /*
                             * Get the type
                             */
                            if (poi_val == "RESTAURANT")
                                local_type = RESTAURANT;

                            else if (poi_val == "SIGHTSEEING")
                                local_type = SIGHTSEEING;

                            else if (poi_val == "CLUB")
                                local_type = CLUB;

                            else if (poi_val == "NATURE")
                                local_type = NATURE;

                            else if (poi_val == "MALL")
                                local_type = MALL;

                            p++;
                        }

                        else if (p % POIFields == 1)
                        {
                            local_name_poi = poi_val;

                            p++;
                        }
                        else if (p % POIFields == 2)
                        {
                            local_desc = poi_val;
                            p++;
                        }
                        else if (p % POIFields == 3)
                        {
                            int j = 0;
                            while (poi_val[j])
                            {
                                if (isalpha(poi_val[j]))
                                {
                                    poi_error = false;

                                    cout
                                            << "Error!Alphabetic characters not allowed for latitude in line"
                                            << poi_line_no << "" << endl
                                            << endl;
                                }
                                j++;
                            }

                            for (unsigned int i = 0; i < poi_val.length(); i++)
                            {
                                if (poi_val[i] == ',')
                                    poi_val[i] = '.';
                            }

                            local_lat_poi = atof(poi_val.c_str());
                            p++;
                        }
                        else if (p % POIFields == 4)
                        {

                            int j = 0;
                            while (poi_val[j])
                            {
                                if (isalpha(poi_val[j]))
                                {
                                    poi_error = false;

                                    cout
                                            << "Error!Alphabetic characters not allowed for Longitude in line"
                                            << poi_line_no << "" << endl
                                            << endl;
                                }
                                j++;
                            }

                            for (unsigned int i = 0; i < poi_val.length(); i++)
                            {
                                if (poi_val[i] == ',')
                                    poi_val[i] = '.';
                            }

                            local_long_poi = atof(poi_val.c_str());

                            poi1.set(local_type, local_name_poi, local_desc,
                                    local_lat_poi, local_long_poi);

                            p++;

                        }

                    }

                    /*
                     * If no errors then add to the database
                     */
                    if (poi_error == true)
                    {

                        local_poi.addPoi(poi1);
                    }
                    poi_error = true;

                }
                /*
                 * Keep track of Line numbers
                 */
                poi_line_no++;
            }
            else
            {
                ;
            }

        }
        poiDb = local_poi;
        local_poi.print();

        file_poi.close();

    }
    else
    {
        return false;
    }

    return true;
}

CFileStore::~CFileStore()
{
    // TODO Auto-generated destructor stub
}

