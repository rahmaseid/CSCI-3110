/* Pass #1: I have been experiencing burnout for the past couple weeks, which has impacted my ability to complete this project on time.

 PROGRAMMER:  Rahma Seid
 Program Description:
  This program creates a flight itinerary for the user by utlizing classes, (STL) vectors, and lists. 
  
  The input consists of two files: one file contains a list of cities, which is used to populate a vector of cities, and the other file contains flight details such as origins, destinations, flight numbers, and prices. This data is used to develop an adjacency list representing the flight map, which shows the available flights between cities (or to and from origin and destination). 
  
  The program outputs the flight information including the origin, destination, flight number, and total flight price, allowing the user to view the available flight options between their selected cities.

*/ 

#include <iostream>   //Preprocessor directives 
#include <fstream>
#include <algorithm>
using namespace std;

#include "flightMap.h"

int main() {
	//Creation of the oneMap object.
	FlightMapClass oneMap;

	//Declartions of the ifstream file_object and the other_object to be used when reading data fron the file
	ifstream file_object,other_object, test_object; 

	
	//Opening the cities.dat file for reading and sending in the file_object into the oneMap member function 
	file_object.open("cities.dat");
	oneMap.Read_cities(file_object);


	//Opening the flight.day file for reading and sending in the other_object into the oneMap member function 
	other_object.open("flights.dat");
	oneMap.Build_map(other_object);

	string first_city;
	string next_city;

	
	test_object.open("requests.dat");
	while(test_object >> first_city){
		test_object >> next_city;
		oneMap.FindPath(first_city, next_city);
	}

	//closing the file objects once done reading 
    file_object.close();
    other_object.close();
	test_object.close();
}