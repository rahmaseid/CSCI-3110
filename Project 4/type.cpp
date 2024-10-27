#include "type.h"

// Define the overloaded methods for struct type here
#include <iostream>
#include <fstream>
using namespace std;

//Overloaded < operator that returns a boolean result if the destination on the left handed side is less that the destination on the rhs side
bool flightRec::operator<(const flightRec &rhs) const {
    if (destination < rhs.destination){
        return true;
    }
    else{
        return false;
    }
}

//Overloaded operator that returns a boolean result if the two destinations & origins are equal
bool flightRec::operator==(const flightRec &rhs) const {
    if((origin == rhs.origin) && (destination == rhs.destination)){
        return true;
    }
    else{
        return false;
    }
}

//Overloading the << operator to print out the flight information
ostream& operator<<(ostream &os, const flightRec &flight){
	os << flight.origin << flight.flightNum << flight.destination << flight.price;
	return os;
}



