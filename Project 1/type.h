// Declare the student type in this header file
#ifndef TYPE__H
#define TYPE__H

#include <string>
// Include this file in your main program file
const int MAX_SCORES = 6; // # of score categories
const int MAX_STUDENTS = 17; // Maximum # of students

struct StudentType{
    std::string classID;
    std::string name;
    int scores[MAX_SCORES]; //Array holds scores for CLA, OLA, Quiz, HW, Exam, Bonus
};

//Function Prototypes
void readStudentData(const std::string& filename, StudentType roster[], int& numStudents); //function to read from text file
void printAllStudents(const StudentType roster[], int numStudents); //function to print info of all the students in table form
void printStudentByID(const StudentType roster[], int numStudents, const std::string& classID); //function to print info of one student, with label for each data
bool isValidClassID(const StudentType roster[], int numStudents, const std::string& classID); //function to check whether a class ID is valid
void sortStudentsByName(StudentType roster[], int numStudents); //function to sort all students by name

#endif