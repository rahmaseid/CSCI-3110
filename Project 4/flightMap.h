#include <iostream>
#include <fstream>
#include <list>
#include <vector>

#ifndef FLIGHTMAPCLASS_H
#define FLIGHTMAPCLASS_H

#include "type.h"

using namespace std;

class FlightMapClass{
	public:
		//constructors and destructor
		FlightMapClass();
	    ~FlightMapClass();

		FlightMapClass(const FlightMapClass &f);
		// copy constructor

		//FlightMapClass operations
		void Read_cities(ifstream &file_object);
		// Reads cities from a data file

		void Build_map(ifstream &myFlights);
		//Reads flight information and build the adjacency list

		void DisplayMap();
		//Displays the flight map in a formatted table

		bool CheckCity(string cityName) const;
		//Checks whether a city is in the cities that the airline serves

		void DisplayAllCities() const;
		//Displays all of the cities

		void MarkVisited(int city);
		//Marks a city as visited

		void UnvisitAll();
		//Clears markers on all cities

		bool IsVisited(int city) const;
		//Determines whether a city was visited or not

		bool GetNextCity(string fromCity, string &nextCity);
		//Determines the next unvisited city

		string GetCityName(int cityNumber) const;

		int GetCityNumber(string cityName) const;
		//Returns the name of a city, given its index

		void FindPath(string originCity, string destinationCity);
		//Determines whether a sequence of flights between two cities exists

		friend ostream& operator<<(ostream& os, const FlightMapClass& rhs);


	private:
		int num_of_cities; //number of cities
   		vector<string> cities; //list of cities
       	list<flightRec> *map; //flight map

		vector<bool> visited; //To check if a city has been visited before
};

#endif