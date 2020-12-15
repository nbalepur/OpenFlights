# include "Airport.h"

using std::string;

Airport::Airport(){};

Airport::Airport(string name, int ID, string IATA, string ICAO, float latitude, float longuitude):
name_(name), ID_(ID), IATA_(IATA), ICAO_(ICAO), latitude_(latitude), longuitude_(longuitude){}

string Airport::getName(){
    return name_;
}

int Airport::getID(){
    return ID_;
}

string Airport::getIATA(){
    return IATA_;
}

string Airport::getICAO(){
    return ICAO_;
}

float Airport::getLatitude(){
    return latitude_;
}

float Airport::getLongitude(){
    return longuitude_;
}