#ifndef Type_H
#define Type_H

#include <iostream>
#include <fstream>
using namespace std;

//define struct flightRec
struct flightRec{
	string origin;
	int flightNum;
	string destination;
	int price;

	//declare overloaded < operator for flightRec
	//this function compares the destinations between two flightRec
	bool operator < (const flightRec & rhs) const;

	//declare overloaded == operator for flightRec
	//this function compares the origins and destinations between two flightRec
	bool operator == (const flightRec & rhs) const;

	//declare overloaded output << (insertion) operator for flightRec struct
	friend ostream& operator << (ostream & os, const flightRec & flight);

};

#endif




