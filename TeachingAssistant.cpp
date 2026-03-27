#include "TeachingAssistant.h"
#include <iostream>
using namespace std;

// Constructor, this explicitly calls the virtual base UniversityMember constructor first
TeachingAssistant::TeachingAssistant(string name, int memberID, double cgpa,
                                     double salary, AccessCard card, int workingHours)
    : UniversityMember(name, memberID),   // Initialize the virtual base directly
      Student(name, memberID, cgpa),      // Student part (CGPA)
      Staff(name, memberID, salary, card) // Staff part (salary and card)
{
    this->workingHours = workingHours;
}

// Overrides displayRole()
void TeachingAssistant::displayRole() //This function returns nothing as it is void
{ 
    cout << "Role: Teaching Assistant | Name: " << getName()
         << " | ID: " << getMemberID()
         << " | CGPA: " << getCGPA()
         << " | Salary: " << getSalary()
         << " | Working Hours: " << workingHours << endl;
}

// Compile- Time Polymorphism
// Called when an integer score is passed 
void TeachingAssistant::gradeAssignment(int score)
{
    cout << "Grading assignment with numeric score: " << score << "/100" << endl;
}

// Compile- Time Polymorphism
// Called when a string letter grade is passed 
void TeachingAssistant::gradeAssignment(string letterGrade)
{
    cout << "Grading assignment with letter grade: " << letterGrade << endl;
}