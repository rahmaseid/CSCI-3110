// Rahma Seid
// Project Description: Write a program that provides a way for you to search and display information of students in the class

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "student.h" //Include Student Type function
#include "roster.h" //Include functions from roster


using namespace std;

int main() {
    int amount;
    bool id_result; //will hold true or false
    string user_id; //will hold the id the roster is looking for
    string className;
    
    
    Roster classRoster(" ");

    //Load the student roster from the file
    classRoster.readStudentRecord("grades.dat");
    amount = classRoster.GetStudentCount();
    className = classRoster.getcourseName();


    cout << "Here is the information for the " << amount << " students in Class " << className << endl;
    cout<<"   "<<setw(3)<<"ClassID"<<"       "<<setw(8)<<"Name"<<"  "<<setw(8)<<"CLA"<<"       "<<setw(1)<<"OLA"<<setw(4)<<"      "<<"Quiz"<<"  "<<setw(3)<<"Homework"<<setw(8)<<"Exam"<<setw(4)<<"    "<<"Bonus"<< endl;
    cout << endl;

    //Print the entire roster
    cout << classRoster << endl;
    cout << endl;

    // Prompt user for valid student Class ID
    cout << "Enter a valid Class ID: ";
    cin >> user_id;

    id_result = classRoster.isValid(user_id);

    while (id_result == 0){ //while loop will repeat until existing class id is found
        cout << endl;
        cout << "Enter a valid Class ID: ";
        cin >> user_id;
        id_result = classRoster.isValid(user_id);
    }

    //Once student id is found, display that student's info
    cout << "Information for the student with ID " << endl;
    cout << "Here is the information for student with ID : " << endl;

    classRoster.ShowOneStudent(user_id);

    return 0;
}