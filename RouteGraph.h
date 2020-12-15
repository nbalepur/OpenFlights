#pragma once

/* needed std structures */
#include <string>
#include <unordered_map>
#include <queue>

/* external structures and functions */
#include "graph.h"
#include "AirportList.hpp"
#include "Utility.h"

/* shorthand imports */
using std::string;
using std::unordered_map;
using std::queue;
using std::pair;

/* helpful typdefs */
typedef pair<string, string> Route;
typedef pair<float, float> Location;
typedef pair<Route, pair<Location, Location>> RouteDistance; 

/**
* Class to store information about the airport routes
* Supports BFS and Djikstra's Algorithm
*/
class RouteGraph {

    public:

        /**
        * Empty constructor to supress errors
        */
        RouteGraph();

        /**
         * Default constructor to create a RouteGraph
         * @param fileName : the name of the file containing the routes
         * @param airportList : object containing airport information
         */
        RouteGraph(string fileName, AirportList airportList);

        /**
         * Finds all of the routes in the data
         * @return a vector of objects representing a route
         */
        vector<RouteDistance> getAllRoutes();

        /* --------------- getters --------------- */

        int getNumAirports();

        int getNumConnections();

        Graph getGraph();

    private:
    
        /**
         * Helper function to parse the data
         * Initializes the graph by creating a parsed Route object
         * @param fileName : the name of the file containing the routes
         */
        void parseRoutes(string fileName);

        /**
         * Parses single entry of the data table
         * @param entry : a single entry of the data table
         * @return object representing the route
         */
        Route parseEntry(string entry);

        /**
         * Helper BFS function that uses a given vertex
         * @param vertex : The current vertex
         * @param routes : A list of routes
         */
        void BFS(Vertex vertex, vector<RouteDistance>& routes);

        /* initialize graph object */
        Graph graph_ = Graph(true, true);

        /* initialize map for tracking visits */
        unordered_map<string, bool> visitedMap_ = unordered_map<string, bool>();

        /* initialize map for storing airport locations */
        unordered_map<string, Location> airportLocations_ = unordered_map<string, Location>();
};