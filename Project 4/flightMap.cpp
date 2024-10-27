#include "flightMap.h"

// implement the methods of the flightMap class here
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <stdbool.h>
#include <deque>

//constructors and destructor
FlightMapClass::FlightMapClass(){
    num_of_cities = 0;
    map = NULL;
}

FlightMapClass::~FlightMapClass(){
	if (map != NULL){
		delete[] map;
	}
}
    
	
//FlightMapClass operations:
void FlightMapClass::Read_cities(ifstream &file_object){
	string city_num;
	string city_names;

	getline(file_object, city_num);

	num_of_cities = stoi(city_num);

	cities.reserve(num_of_cities);
		visited.reserve(num_of_cities);

	while (getline(file_object, city_names)){
		cities.push_back(city_names);
		visited.push_back(false);
	}

	sort(cities.begin(), cities.end());
}

void FlightMapClass::Build_map(ifstream &file_object){
	map = new list<flightRec>[num_of_cities];

	int flight_num, price;
	string origin, destination;

	flightRec One_flight;

	while (file_object >> flight_num >> origin >> destination >> price){
		One_flight.flightNum = flight_num;
		One_flight.origin = origin;
		One_flight.destination = destination;
		One_flight.price = price;

		for (int i = 0; i < num_of_cities; i++){
			if (cities[i] == One_flight.origin){
				map[i].push_back(One_flight);
			}
		}
	}
	for (int i = 0; i < num_of_cities; i++) {
        map[i].sort();
    }
}

void FlightMapClass::DisplayMap(){
	cout << left << setw(24) << "        Origin " << setw(15) << "Destination"
		<< setw(9) << "Flight"
		<< "Price" << endl;

	cout << "==============================================" << endl;
	cout << endl;

	//For loop to iterate through number of cities
	for (int i = 0; i < num_of_cities; i++){
		list<flightRec>::iterator itr;

		cout << " From " << cities[i]
			<< setw(18 - cities[i].length()) << " to:  ";

		int counter = 0;
		
		for (itr = map[i].begin(); itr != map[i].end(); itr++){
			if (itr != map[i].begin()){
				cout << setw(24) << left << "";
				cout << setw(15) << itr->destination;
				cout << setw(9) << itr->flightNum;
				cout << "$" << itr->price << endl;
			}

			else{
				cout << setw(15) << itr->destination;
				cout << setw(9) << itr->flightNum;
				cout << "$" << itr->price << endl;

				//Increment counter since its not the first one in the row
				counter++;
			}
		}
		//If ccounter is qual to zeero, that means there was nothing in the first row, 
		//so then we can insert a new line
		if (counter == 0){
			cout << endl;
		}
	}
	return;
}

bool FlightMapClass::CheckCity(string cityName) const {
	//Declare city iterator
	vector<string>::const_iterator city_iterator = cities.begin();

	for (city_iterator = cities.begin(); city_iterator != cities.end(); city_iterator++){
		if (*city_iterator == cityName){
			return true;
		}
	}
	//If it doesn't match, we return false
	return false;
}

void FlightMapClass::DisplayAllCities() const {
	vector<string>::const_iterator it;

	for (it = cities.begin(); it != cities.end(); it++){
		cout << *it << endl;
	}
}

//Dsiplays all of cities function
void FlightMapClass::MarkVisited(int city) {
	visited[city] = true;
}

void FlightMapClass::UnvisitAll(){
	//Declare iterator of vector bool type
	vector<bool>::iterator iterator;

	for (iterator = visited.begin(); iterator != visited.end(); iterator++){
		*iterator = false;
	}
}

bool FlightMapClass::IsVisited(int city) const {
	return visited[city];
}

bool FlightMapClass::GetNextCity(string fromCity, string &nextCity) {
	int index_position = GetCityNumber(fromCity);

	//Next we need to iterate through the flight map and boolean vector of visited cities to see
	//whether its been visited
	list<flightRec>& lists_for_destination = map[index_position];

	list<flightRec>::iterator iter = lists_for_destination.begin();

	for (iter = lists_for_destination.begin(); iter != lists_for_destination.end(); iter++){
		if (!visited[GetCityNumber(iter->destination)]) {
			nextCity = iter->destination;
			return true;
		}
	}
	return false;	
}

int FlightMapClass::GetCityNumber(string cityName) const {
	int i = 0;

	for (int i = 0; i < num_of_cities; i++){
		if(cities[i]==cityName) {
			return i;
		}
	}
	return -1;
}

string FlightMapClass::GetCityName(int cityNumber) const {
	return cities[cityNumber];
}

void FlightMapClass::FindPath(string originCity, string destinationCity) {
	//print request to fly from originCity to destCity to user
	cout << "Request is to fly from " << originCity << " to " << destinationCity << "." << endl;

	stack<int> flightstack;

	//Declare variable below
	string next_city;
	int total_accumulator = 0;
	int top_index;
	int first_city_index, destination_index, next_city_index;

	bool success; //varaibale holds either true or false;

	UnvisitAll();

	if (!CheckCity(originCity)){
		cout << "Sorry, BlueSky airline does not fly from " << originCity << " to " << destinationCity << "." << endl;
		return;
	}

	if (!CheckCity(destinationCity)) {
		cout << "Sorry, BlueSky airline does not serve " << destinationCity << "." << endl;
		return;
	}

	destination_index = GetCityNumber(destinationCity);
	first_city_index = GetCityNumber(originCity);
	
	flightstack.push(first_city_index);
	MarkVisited(first_city_index);

	while(!flightstack.empty() && (flightstack.top() != destination_index)) {
		success = GetNextCity(GetCityName(flightstack.top()),next_city);

		if(!success) {
			flightstack.pop();
		}

		else{
			next_city_index = GetCityNumber(next_city);
			flightstack.push(next_city_index);

			MarkVisited(next_city_index);
		}

	}

	//If the flightstack is empty, then the places are valid but there are no connecting flights
	if(flightstack.empty()){
		cout << "Sorry, BlueSky airline does not fly from " << originCity << " to " << destinationCity << "." << endl;
		cout << endl;
		return;
	}

	//Print out the message that show the two cities served by the airline
	cout << "BlueSky airline serves between these two cities." << endl;
	cout << "The Flight itinerary is: " << endl;
	cout << "Flight #        From            To               Cost" << endl;

	deque<string> copy_flightstack; //declare a deque of string to hold the string names of the cities

	while(!flightstack.empty()){
		top_index = flightstack.top();  //Setting top_index to the flightstack's top
		flightstack.pop(); //pop it off
		copy_flightstack.push_front(GetCityName(top_index));
	}

	for (int i = 0; i < copy_flightstack.size()-1; i++) {
		string origin = copy_flightstack[i];
		string destination = copy_flightstack[i+1];
		list<flightRec>::iterator iterator = map[GetCityNumber(origin)].begin();

		for (iterator = map[GetCityNumber(origin)].begin(); iterator != map[GetCityNumber(origin)].end(); iterator++ ) {
			if (iterator->destination == destination) {
				cout << left << setw(16) << iterator->flightNum << setw(16) << left << iterator->origin << setw(17) << iterator->destination << "$" << iterator->price << endl;

				total_accumulator +=iterator->price;  //Have the total  accumulator take in total amount
			}
		}
		
	}

	//print out total in the end
	cout << right << setw(50) << "Total:    $" << total_accumulator << endl;
	cout << endl;
}





























