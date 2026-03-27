#ifndef STUDENT_H
#define STUDENT_H

#include "UniversityMember.h" //Linker

// Student class represents a university student with a CGPA
// Uses Virtual inheritance from UniversityMember 
// When TeachingAssistant inherits from both Student and Staff,
// virtual inheritance ensures only one copy of UniversityMember exists
class Student : virtual public UniversityMember
{
private:
    double cgpa;;    // CGPA in double, with a decimal point

public:
    // Constructor
    Student(string name, int memberID, double cgpa);
     
    // Getter
    // Returns the student's current CGPA
    double getCGPA() const;
  
    // Updates the student's CGPA according to what the user input
    void updateCGPA(double newCGPA);

    void displayRole() override;
};

#endif