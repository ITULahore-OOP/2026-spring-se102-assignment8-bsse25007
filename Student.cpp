#include "Student.h"
#include <iostream>
using namespace std;

// Constructor, initializes base class first, then sets cgpa
Student::Student(string name, int memberID, double cgpa)
    : UniversityMember(name, memberID)
{
    this->cgpa = cgpa;
}

// Returns the student's CGPA
double Student::getCGPA() const
{
    return cgpa;
}

// Updates the student's CGPA to a new value provided by the user
void Student::updateCGPA(double newCGPA)
{
    cgpa = newCGPA;
}


// This is called at runtime when a base class pointer points to a Student object
void Student::displayRole()
{
    cout << "Role: Student | Name: " << getName() << " | ID: " << getMemberID()
         << " | CGPA: " << cgpa << endl;
}