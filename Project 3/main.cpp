//Rahma Seid
//CSCI 3110
//Project 4: Your program should start by reading in a list of city names for which the company currently serves. The list of names is stored in a data file named “cities.dat”. Then, your program reads in a list of flights currently served by the company. The flight information is stored in the data file “flights.dat”.

#include <iostream>   //Preprocessor directives 
#include <fstream>
#include <algorithm>
using namespace std;

#include "flightMap.h"

int main() {
	//Creation of the oneMap object.
	FlightMapClass oneMap;

	//Declartions of the ifstream file_object and the other_object to be used when reading data fron the file
	ifstream file_object,other_object; 

	//Opening the cities.dat file for reading and sending in the file_object into the oneMap member function 
	file_object.open("cities.dat");
	oneMap.Read_cities(file_object);

	//Opening the flight.day file for reading and sending in the other_object into the oneMap member function 
	other_object.open("flights.dat");
	oneMap.Read_and_build_map(other_object);

	//Printing out the Flight Map using the overloaded << operator 
	cout<<oneMap;

	//closing the flie objects once done reading 
    file_object.close();
    other_object.close();
}