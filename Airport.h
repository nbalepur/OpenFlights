# pragma once
# include <string>

using std::string;

class Airport{
    public:
        // Constructor
        Airport();

        Airport(string name, int ID, string IATA, string ICAO, float latitude, float longuitude);
    
        string getName();

        int getID();

        string getIATA();

        string getICAO();

        float getLatitude();

        float getLongitude();

    private:
        string name_;
        int ID_;
        string IATA_;
        string ICAO_;
        float latitude_;
        float longuitude_;
};