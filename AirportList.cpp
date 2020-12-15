# include "AirportList.hpp"
# include "readFromFile.hpp"
# include <iostream>

using std::string;
using std::vector;
using std::unordered_map;
using std::pair;

AirportList::AirportList(){
    count_ = 0;
}

AirportList::AirportList(string filename){
    string data = file_to_string(filename);
    string delimiter = "\n";
    size_t pos = 0;
    vector<string> elems;
    // parse the data and store in vectors
    while((pos = data.find(delimiter)) != string::npos){
        elems.push_back(data.substr(0,pos));
        data.erase(0, pos + delimiter.length());
    }
    elems.push_back(data);
    
    // traverse through the data vectors and transfer them into airport objects
    for(const string& entry : elems){
        parseData(entry);
    }

    count_ = list_.size();
}

int AirportList::getNum(){
    // return the number of airports in the list;
    return count_;
}

vector<Airport> AirportList::getList(){
    // return the airport list
    return list_;
}

Airport AirportList::find(string Identifier){
    for(Airport obj : list_){
        // check whether the given identifier matches the object
        if (obj.getIATA() == Identifier) return obj;
        if (obj.getICAO() == Identifier) return obj;
    }
    return Airport();
}

unordered_map<string,pair<float,float> > AirportList::getMap(){
    unordered_map<string,pair<float,float>> memo;
    // update the map for each airport object present
    for (Airport air : list_){
        memo.insert(pair<string, pair<float,float> >(std::to_string(air.getID()), pair<float,float>(air.getLatitude(),air.getLongitude())));
    }
    return memo;
}

void AirportList::parseData(string entry){
    // declare variables needed for paesing data
    string delimiter = ",";
    size_t pos = 0;
    vector<string> elems;
    // parse the data and store in vectors
    while((pos = entry.find(delimiter)) != string::npos){
        elems.push_back(entry.substr(0,pos));
        entry.erase(0, pos + delimiter.length());
    }
    elems.push_back(entry);
    // make sure the entry has valid data
    if (elems.size() < 10) return;
    // construct the object and update it 
    // std::cout<< elems[0] << elems[1] << elems[6] << "," << elems[7] << std::endl;
    Airport air(elems[1],std::stoi(elems[0],nullptr,10),elems[4],elems[5],std::stof(elems[6]),std::stof(elems[7]));
    list_.push_back(air);
}