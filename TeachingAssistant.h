#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Staff.h"

// TeachingAssistant inherits from both Student and Staff

 
class TeachingAssistant : public Student, public Staff
{
private:
    int workingHours;   // Number of hours the TA works per week

public:
    // Constructor
    TeachingAssistant(string name, int memberID, double cgpa,
                      double salary, AccessCard card, int workingHours);

    // Overrides displayRole() from UniversityMember 
    void displayRole() override;

    // Overloaded gradeAssignment, compile-time polymorphism
    // Version 1: grade by int score
    void gradeAssignment(int score);

    // Version 2: grade by letter grade 
    void gradeAssignment(string letterGrade);
};

#endif