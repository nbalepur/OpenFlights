#pragma once

#include "RouteGraph.h"
#include "AirportList.hpp"
#include "cs225/PNG.h"
#include "Animation.h"
#include "dijkstra.hpp"

#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

typedef std::pair<int, int> Coordinate;

class MapImage {

    public:

        /**
        * Creates a map image by initializing a RouteGraph object
        * @param airportFile : the file location of the airport dataset
        * @param routeFile : the file location of the routes dataset
        */
        MapImage(string airportFile, string routeFile);

        /**
        * Draws the shortest path between two airports using Dijkstra's algorithm
        * @param source : the source airport
        * @param dest : the destination airport
        * @param outFileName : the file location to be written to
        */
        void drawShortestPath(string source, string dest, string outFileName);

        /**
        * @param outFileName : the file location to be written to
        */
        void playAnimation(string outFileName);

    private:

        /* constant variables */
        const int FRAME_SPEED = 10;

        const cs225::HSLAPixel POINT_PIXEL = cs225::HSLAPixel(20, 1, 0.5, 1);
        const cs225::HSLAPixel BORDER_PIXEL = cs225::HSLAPixel(20, 1, 0.65, 1);
        const cs225::HSLAPixel ROUTE_PIXEL = cs225::HSLAPixel(120, 1, 0.5, 1);

        /* data structure storing airport connections */
        RouteGraph graph_;

        /* structure to hold animation information */
        Animation animation_;

        /* map background image */
        cs225::PNG backgroundImage_;

        /* unordered map to lookup coordinates */
        unordered_map<string, Coordinate> locationMap_ = unordered_map<string, Coordinate>();

        /* image adjustments */
        int adjHeight_;
        int adjWidth_;
        int offset_;

        /**
        * Helper function to draw the border of every point on the map
        * @param coord : the coordinate of the location
        * @param color : the color of the border
        * @param png : the image to modify
        */
        void drawPointBorders(Coordinate coord, const cs225::HSLAPixel color, cs225::PNG& png);

        /**
         * Helper function to draw Line between two coordinates
         * @param start the starting Coordinate
         * @param end the ending Coordinate
         * @param color the color to draw the line with
         * @param png the PNG to draw the line on
         * @param frameCounter the current frame count
         */
        void drawLine(Coordinate start, Coordinate end, const cs225::HSLAPixel color, cs225::PNG& png, int& frameCounter);

        /** Initializes the map to locate airport xy-coordinates for O(1) lookup
        * @param routes : a vector of RouteDistances obtained from the RouteGraph BFS
        */
        void initializeLocationMap(vector<RouteDistance> routes);

        /**
        * Helper function to add an airport to the unordered map
        * First checks to make sure the airport is not already in the unordered map
        * @param airport : the unique ID of the airport
        * @param location : the latitude/longitude location of the airport
        */
        void addLocation(string airport, Location location);

        /**
        * Draws the location and connection of airports on the image
        * @param image : the desired image output
        */
        void drawAirports(cs225::PNG& image);

        /**
         * Draws a Line between two airports. Does not draw the whole path. 
         * @param source The airport to depart from
         * @param dest The airport to travel to
         * @param image Reference to the png being written to
         * @param frameCounter Counter for the current frame
         */
        void drawRoute(string source, string dest, cs225::PNG& image, int& frameCounter);
};