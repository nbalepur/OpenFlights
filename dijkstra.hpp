# pragma once

# include <vector>
# include <string>
# include <map>
# include "AirportList.hpp"
# include "RouteGraph.h"
# include "Utility.h"
# include <limits>
# include "graph.h" 

using std::vector;
using std::string;
using std::map;

typedef pair<string, string> Route;
typedef pair<float, float> Location;
typedef pair<Route, pair<Location, Location>> RouteDistance; 


class Dijkstra {
    public:
        class node{
            public:
                node();
                bool visited;
                string prev;
                double dist;
        };

        Dijkstra(RouteGraph obj);

        vector<string> findShortestPath(string start, string end);

    private:
        map<string,node> Vertex_;
        vector<RouteDistance> Edge_;
        map<Route,double> Route_;
        map<string, vector<string> > adjacency;
        string find_min(vector<string> Q);
        Graph graph_ = Graph(true,true);
};