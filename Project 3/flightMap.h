#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

#include "type.h"

using namespace std;

class FlightMapClass
{
	public:
		//constructors and destructor
		FlightMapClass();
        ~FlightMapClass();
    
	
		//FlightMapClass operations:
        int Get_num() const;
        

		//Read cities from a data file
		//Pre-condition: Input stream is provided
		//Post-condition: Data file is read
		//				  Cities are in ascending order
        void Read_cities(ifstream &file_object);

		//Reads flight information and build the adjacency list
		//Pre-condition: list of the flight information is provided
		//Post-condition: Flight map is built
		void Read_and_build_map(ifstream & file_object);
		
		//Displays the flight map in a formatted table
	    // using overloaded << opererator
		//Pre-condition: none
		//Post-condition: Flight map is displayed

        friend ostream& operator<<(ostream& os, const FlightMapClass& rhs);
		
	private:
        int number_of_cities; //number of cities
   		vector<string>vector_of_cities; //vector of cities
       	list<flightRec>*flight_map;//flight map
};

#endif
