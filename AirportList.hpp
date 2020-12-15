# pragma once
# include <string>
# include <vector>
# include <unordered_map>
# include <utility>
# include "Airport.h"

using std::string;
using std::vector;
using std::unordered_map;
using std::pair;

class AirportList{
    public:

        /**
         * Default Constructor that creates
         * a empty list
         */
        AirportList();

        /** 
         * Constructor that creates a
         * list of airport objects from the given
         * dataset file.
         */
        AirportList(string filename);

        /**
         * Get the number pf airports that 
         * are recorded into the list from
         * the dataset file.
         */
        int getNum();

        /**
         * Returns the list of airports in 
         * the form of vector.
         */
        vector<Airport> getList();

        /**
         * Returns the airport whose IATA or ICAO matches the 
         * given argument.
         */
        Airport find(string Identifier); 

        /**
         * Returns a map which keys are ID of airports and values
         * are pairs of the airports' location(longitude and latitude)
         */
        unordered_map<string,pair<float,float>> getMap();

    private:
        /**
         * The vector that stores all the airports.
         */
        vector<Airport> list_;

        /**
         * The variable that keeps track of all airports.
         */
        int count_;

        /**
         * Private helper function that helps parse string 
         * data converted from dataset into airport identifier
         * information and creates the airport class while 
         * updating the list_ and count_.
         */
        void parseData(string data);
};