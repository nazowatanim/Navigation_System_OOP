#include<iostream>
//Own Include Files
#include "CPOI.h"
#include<string>
using namespace std;

//Method to print the Point of Interests
void CPOI::print(int format)
{

    string name, description;
    t_poi type;
    double latitude, longitude;

        latitude = getLatitude();   //Gets the latitude using method from CWaypoint
        longitude = getLongitude(); //Gets the longitude using method from CWaypoint
        name = getName();               //Gets the name using method from CWaypoint
        type = m_type;
        description = m_description;



    cout << "Point of Interest" << endl;
    cout << "=================================" << endl;

    /*
     * To get the type of enum
     */
    switch (type)
    {

    case RESTAURANT:
        cout << " of type RESTAURANT : " << description << "" << endl<<endl;
        break;

    case SIGHTSEEING:
        cout << " of type SIGHTSEEING : " << description << "" << endl<<endl;
        break;

    case CLUB:
        cout << " of type CLUB : " << description << "" << endl<<endl;
        break;

    case NATURE:
        cout << " of type NATURE : " << description << "" << endl<<endl;
        break;

    case MALL:
        cout << " of type MALL : " << description << "" << endl<<endl;
        break;

    }

    /*
     * Uses CWaypoint print function to print the Point of Interest
     */
    CWaypoint::print(degree);

}

//Constructor
CPOI::CPOI(t_poi type, string name, string description, double latitude,
        double longitude)
{
    m_description = description;
    m_type = type;
    m_latitude = latitude;
    m_longitude = longitude;
    m_name = name;


}
//CPOI::~CPOI(){}


CPOI::CPOI()
{

// m_type = RESTAURANT;

}

//Overload operator
ostream& operator<<(ostream& out, const CPOI& c)
{
    /*
     * As const c hence local variable assignment needed.
     */
    CPOI mPoi=c;
    int deg_lat,mm_lat;
    int deg_long,mm_long;
    double ss_lat,ss_long;
    double l_latitude,l_longitude;
    string l_name,l_description;
    t_poi type;
    l_name=mPoi.getName();
    l_latitude=mPoi.getLatitude();
    l_longitude=mPoi.getLongitude();
    type=mPoi.m_type;
    l_description=mPoi.m_description;

/*
 * To display the latitude in deg mm ss format
 */
    deg_lat = (int) l_latitude;
            mm_lat = (int) ((l_latitude - (float) deg_lat) * 60.0);
            ss_lat = (((l_latitude - deg_lat) * 3600.0)) - (((float) mm_lat) * 60);
/*
 * * To display the Longitude in deg mm ss format
 */

        deg_long = (int) l_longitude;
        mm_long = (int) ((l_longitude - (float) deg_long) * 60.0);
        ss_long = (((l_longitude - deg_long) * 3600.0)) - (((float) mm_long) * 60);


        cout << "Point Of Interest" << endl;
        cout << "=================================" << endl;

        /*
         * To get the type of enum
         */
        switch (type)
        {

        case RESTAURANT:
            cout << " of type RESTAURANT : " << l_description << "" << endl;
            break;

        case SIGHTSEEING:
            cout << " of type SIGHTSEEING : " << l_description << "" << endl;
            break;

        case CLUB:
            cout << " of type CLUB : " << l_description << "" << endl;
            break;

        case NATURE:
            cout << " of type NATURE : " << l_description << "" << endl;
            break;

        case MALL:
            cout << " of type MALL : " << l_description << "" << endl;
            break;

        }


        out<<" " << l_name << "  on latitude " << deg_lat << " deg " << mm_lat<< "min " << ss_lat << "s";

        out<<"   and " << deg_long << " deg " << mm_long
                        << "min " << ss_long << "s"<<endl;




    // out<<" " << c.m_name << " on latitude " << c.m_latitude<< " and longitude " << c.m_longitude << " " << endl<<endl;
     return out;
}

t_poi CPOI::getType()
{

    return m_type;
}

string CPOI::getDescription()
{

    return m_description;
}

void CPOI::set(t_poi type, string name, string description, double latitude,
        double longitude)
{
    m_type=type;
    m_name=name;
    m_description=description;
    m_latitude=latitude;
    m_longitude=longitude;


}
