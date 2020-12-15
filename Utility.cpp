#include "Utility.h"
# include <utility>
# include <cmath>

using std::pair;

/**
 * Finds the distance in km between two coordinates on the map
 * @param coordinate1 Coordinate of First Airport (Latitude, Longitude) 
 * @param coordinate2 Coordinate of Second Airport (Latitude, Longitude)
 * @return The distance between the two coordinates ignoring elevation
 */

double distance(std::pair<double, double> coordinate1, std::pair<double,double> coordinate2){
    // Reference for this code is taken from https://www.movable-type.co.uk/scripts/latlong.html

    //constants
    double const radiusEarth = 6371 ; // radius in km
    double const PI = atan(1)*4;

    //decomposing first pair
    double lat1 = coordinate1.first;
    double long1 = coordinate1.second;

    //decompoinsing second pair
    double lat2 = coordinate2.first;
    double long2 = coordinate2.second;   
    

    double lat1Rad = lat1 * PI/180;
    double lat2Rad = lat2 * PI/180;
    double deltaLatRad = (lat2 - lat1) * PI/180;
    double deltaLongRad = (long2 - long1) * PI/180;


    double a = (sin(deltaLatRad/2) *sin(deltaLatRad/2))  + cos(lat1Rad) * cos(lat2Rad) * sin(deltaLongRad/2) * sin(deltaLongRad/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return radiusEarth * c;
}

std::pair<int,int> location2graph(std::pair<float,float> location, int width, int height, int vertOffset){
    int w,h;
    w = floor(width/2.0*(1+location.second/180.0)+0.5);
    h = floor(height/2.0*(1+location.first/180.0)+0.5);
    return pair<int,int>(w, height - h - vertOffset);
}
