#include "flightMap.h"

// implement the methods of the flightMap class here
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

//constructors and destructor
FlightMapClass::FlightMapClass(){
    number_of_cities = 0;
    flight_map = NULL;
}

FlightMapClass::~FlightMapClass(){
    delete[] flight_map;
}
    
	
//FlightMapClass operations:
int FlightMapClass::Get_num() const{
    return number_of_cities;
}
        

//Read cities from a data file
//Pre-condition: Input stream is provided
//Post-condition: Data file is read
//				  Cities are in ascending order
void FlightMapClass::Read_cities(ifstream &file_object){
    string city_num;
	string city_names;

	//Reading in the first line from the file (cities.dat) which includes the string amount of the number of cities
	getline(file_object,city_num);

	//conversion of the string of number of cities to an integer
	number_of_cities = stoi(city_num);

	//using the STL vector member function reserve to reserve the number of spaces for each city that we read in
	vector_of_cities.reserve(number_of_cities);

	//Reading from the file to get the different names of the cities and to push back to the vector of cities once we have read one city
	while(getline(file_object, city_names)){
		vector_of_cities.push_back(city_names);
	}

	//Using the sort member function to sort the names of the cities in Alphabetical order starting with the beginning of the vector to the end of the vector of cities. 
	sort(vector_of_cities.begin(),vector_of_cities.end());
    
}

//Reads flight information and build the adjacency list
//Pre-condition: list of the flight information is provided
//Post-condition: Flight map is built
void FlightMapClass::Read_and_build_map(ifstream & file_object){
    flight_map = new list<flightRec> [number_of_cities];

    int flight_number, price;
    string origin, destination;
    
    flightRec Oneflight;

    // Read each flight's details
   while (file_object >> flight_number >> origin >> destination >> price) {
        Oneflight.flightNum = flight_number;
        Oneflight.origin = origin;
        Oneflight.destination = destination;
        Oneflight.price = price;

        // Find the index of the origin city in the vector_of_cities
       for(int index = 0;index<number_of_cities;index++){
			
			//Once we find one that matched, we can then push back the information for that flight into the list of flight map creating the adjacency list of Flight Map
			if(vector_of_cities[index] == Oneflight.origin){
				flight_map[index].push_back(Oneflight);
			}
		}
		//Using the ignore method to ignore characters
		file_object.ignore(100,'\n');
    }
}

ostream& operator<<(ostream& os, const FlightMapClass& rhs){
    os<<left<<setw(24)<<"       Origin "<<setw(15)<<"Destination"<<setw(9)<<"Flight"<<"Price"<<endl;
    os<<"======================================================"<<endl;
	os<<endl;

	//For loop to iterate through the number of cities 
    for(int index=0; index<rhs.number_of_cities; index++){

    		//Declaration of the itr iterator so that we can iterate through the list of flightRec 
        list<flightRec>::iterator itr;
    		
    	//Sorting the information in Alphabetical order
    	rhs.flight_map[index].sort();
    
    		//Printing of the From and To using the set width function and the vector of cities that contain the origins of all the flights
        os<<" From "<<rhs.vector_of_cities[index]<<setw(18-rhs.vector_of_cities[index].length())<<" to: ";
    
    		//Integer counter varaible used to keep track if we need to have a new_line or not
        int counter = 0;

    		//For loop to iterate through the entire flight_map 
        for(itr = rhs.flight_map[index].begin(); itr != rhs.flight_map[index].end(); itr++){
    			
    		//If the iterator does not equal to being (meaning its not the first one in the flight_map) we can setw accordingly 
            if(itr != rhs.flight_map[index].begin()){
                os<<setw(24)<<left<<"";
        		os<<setw(15)<<itr->destination;
                os<<setw(9)<<itr->flightNum;
                os<<"$"<<itr->price<<endl;
          }
    			//else then this is the first row of information in the list then we can spaceout and setw accordingly 		
        	else{
                os<<setw(15)<<itr->destination;
                os<<setw(9)<<itr->flightNum;
                os<<"$"<<itr->price<<endl;
    			//Increment counter since it is not the first one in the row
    			counter++;
    		}
    			
        }
		//If the counter is equal to zero meaing that there was nothing in the first row (so no information) then we can insert a new line 
        if(counter == 0){
            os<<endl;
        }
    }
	//Returning os
    return os;
}
		
