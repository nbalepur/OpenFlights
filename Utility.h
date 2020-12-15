#pragma once

#include <math.h>
#include <utility> 

/**
 * Utility file for Calculations
 */

/**
* Finds the distance in km between two coordinates on the map
* @param coordinate1 Coordinate of First Airport (Latitude, Longitude) 
* @param coordinate2 Coordinate of Second Airport (Latitude, Longitude)
* @return The distance between the two coordinates ignoring elevation
*/
double distance(std::pair<double , double> coordinate1, std::pair<double,double> coordinate2);

/**
* This is a utility function that transfers the latitude and longitude of
* the airport to a pixel in the output graph.
*/
std::pair<int,int> location2graph(std::pair<float,float> location, int width, int height, int vertOffset);
