# include "dijkstra.hpp"
# include "Utility.h"
# include <algorithm>
# include <list>
# include <iostream>

using std::pair;
using std::string;
using std::vector;
using std::remove;

Dijkstra::Dijkstra(RouteGraph obj){
    //std::cout << "in dk constructor" << std::endl;
    Edge_ = obj.getAllRoutes();
    graph_ = obj.getGraph();
    //std::cout << "edges received" << std::endl;
    for (auto i : Edge_){
        Route_.insert(pair<Route,double>(i.first,distance(i.second.first,i.second.first)));
    }
    //std::cout << "routes created" << std::endl;
    for (auto i : graph_.getVertices()){
        Vertex_.insert(pair<string,node>(i,node()));
        //adjacency.insert(pair<string,vector<string> >(i,obj.getGraph().getAdjacent(i)));
    }
    //std::cout << "constructor complete" << std::endl;
}

vector<string> Dijkstra::findShortestPath(string start, string end){
    Vertex_[start].dist = 0.0;
    vector<string> Q;
    string u;
    double alt;
    // std::cout << "in dk algorithm" << std::endl;
    // for (auto i : Vertex_){
    //     Q.push_back(i.first);
    // }
    // std::cout << "Q initialized" << std::endl;    
    // while(!Q.empty()){
    //     u = find_min(Q);
    //     std::cout << "min found" << std::endl;
    //     Q.erase(remove(Q.begin(),Q.end(),u),Q.end());
    //     for (auto i : Q) std::cout << i << std::endl;
    //     std::cout << "Q updated" << std::endl;
    //     if (u == end) break;
    //     for (auto v : graph_.getAdjacent(u)){
    //         alt = Vertex_[u].dist + Route_[pair<string,string>(u,v)];
    //         if (alt < Vertex_[v].dist){
    //             Vertex_[v].dist = alt;
    //             Vertex_[v].prev = u;
    //         }
    //     }
    // }
    // std::cout << "loop begin" << std::endl;

    Q.push_back(start);
    while(!Q.empty()){
        u = find_min(Q);
        // std::cout << u << std::endl;
        // Vertex_[u].visited = true;
        Q.erase(remove(Q.begin(),Q.end(),u),Q.end());
        // for (auto i : Q) std::cout << i << std::endl;
        if (u == end) break;
        // std::cout << "Not break" << std::endl;
        
        for (auto v : graph_.getAdjacent(u)){
            // std::cout << "Inner loop" << std::endl;
            if (Vertex_[v].visited) continue;
            Q.push_back(v);
            Vertex_[v].visited = true;
            alt = Vertex_[u].dist + Route_[pair<string,string>(u,v)];
            if (alt < Vertex_[v].dist){
                // std::cout << "update prev" << std::endl;
                Vertex_[v].dist = alt;
                Vertex_[v].prev = u;
            }
        }
    }

    std::list<string> path;
    u = end;
    if (Vertex_[u].prev != "UNDEFINED" || u ==start){
        while(u != "UNDEFINED"){
            path.push_front(u);
            u = Vertex_[u].prev;
        }
    }
    //std::cout << "form path" << std::endl;

    vector<string> result(path.begin(),path.end());
    return result;
}

string Dijkstra::find_min(vector<string> Q){
    string min_node;
    double min = std::numeric_limits<float>::infinity();
    for (auto i : Q){
        if (Vertex_[i].dist < min){
            min = Vertex_[i].dist;
            min_node = i;
        }
    }
    return min_node;
}

Dijkstra::node::node(){
    visited = false;
    prev = "UNDEFINED"; 
    dist = std::numeric_limits<float>::infinity();
}