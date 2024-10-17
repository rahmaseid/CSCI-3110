/* 
 PROGRAMMER: Rahma Seid 
 Program Description: Write a program that provides a way for you to search and display information of all the students 
in a class. 
  
*/ 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "type.h"

using namespace std;

// Function to read student data from text file
void readStudentData(const std::string& filename, StudentType roster[], int& numStudents) {
    ifstream infile(filename);
    if (!infile) {
        cout << "Error opening file" << endl;
        exit(1);
    }

    numStudents = 0;
    string line;
    
    // Read and ignore the header line
    getline(infile, line);
    while (infile >> roster[numStudents].classID) {
        infile >> roster[numStudents].name
               >> roster[numStudents].scores[0] // CLA
               >> roster[numStudents].scores[1] // OLA
               >> roster[numStudents].scores[2] // Quiz
               >> roster[numStudents].scores[3] // Homework
               >> roster[numStudents].scores[4] // Exam
               >> roster[numStudents].scores[5]; // Bonus

        numStudents++;
    }

    infile.close();
}

// Function to print info of all students in table format
void printAllStudents(const StudentType roster[], int numStudents) {
    cout << left << setw(12) << "Class ID" 
         << setw(15) << "Name" 
         << setw(6) << "CLA"
         << setw(6) << "OLA"
         << setw(7) << "Quiz"
         << setw(12) << "Homework"
         << setw(8) << "Exam"
         << setw(8) << "Bonus"
         << endl;


    for (int i = 0; i < numStudents; i++) {
        cout << setw(12) << roster[i].classID
             << setw(15) << roster[i].name
             << setw(6) << roster[i].scores[0]
             << setw(6) << roster[i].scores[1]
             << setw(7) << roster[i].scores[2]
             << setw(12) << roster[i].scores[3]
             << setw(8) << roster[i].scores[4]
             << setw(8) << roster[i].scores[5]
             << endl;
    }
    cout << endl;
}

// Function to print info of one student by ClassID
void printStudentByID(const StudentType roster[], int numStudents, const std::string& classID) {
    for (int i = 0; i < numStudents; i++) {
        if (roster[i].classID == classID) {
            cout << "Information for student with ID: " << roster[i].classID << endl;
            cout << "Name: " << roster[i].name << endl;
            cout << "CLA: " << roster[i].scores[0] << endl;
            cout << "OLA: " << roster[i].scores[1] << endl;
            cout  << "Quiz: " << roster[i].scores[2] << endl;
            cout << "Homework: " << roster[i].scores[3] << endl;
            cout << "Exam: " << roster[i].scores[4] << endl;
            cout << "Bonus: " << roster[i].scores[5] << endl;
            return;
        }
    }
}

// Function to check whether a class ID is valid
bool isValidClassID(const StudentType roster[], int numStudents, const std::string& classID) {
    for (int i = 0; i < numStudents; i++) {
        if (roster[i].classID == classID) {
            return true;
        }
    }
    return false;
}

// Function to sort all students by name
void sortStudentsByName(StudentType roster[], int numStudents) {
    std::sort(roster, roster + numStudents, [](const StudentType& a, const StudentType& b) { 
        return a.name < b.name;
    }); 
}

int main() {
    StudentType roster[MAX_STUDENTS];
    int numStudents = 0;
    string filename = "grades.dat";

    // Read student data
    readStudentData(filename, roster, numStudents);

    // Display all students
    printAllStudents(roster, numStudents);

    // Prompt user for valid student Class ID
    string classID;
    bool validIDEntered = false;
    while (!validIDEntered) {
        cout << "Enter a valid Class ID: ";
        cin >> classID;

        if (isValidClassID(roster, numStudents, classID)) {
            validIDEntered = true;  // Exit loop if a valid ID is entered
            // Print student details given from class ID
            printStudentByID(roster, numStudents, classID);
            break;
        } 
    }

    

    // Sort students by name and print them
    sortStudentsByName(roster, numStudents);
    cout << "\nSorted list of students by name: \n" << endl;
    cout << "Here is the information of 17 students: \n" << endl;
    printAllStudents(roster, numStudents);

    return 0;
}
