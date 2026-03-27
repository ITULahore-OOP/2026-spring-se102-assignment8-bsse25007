#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "UniversityMember.h"

// Department class manages a collection of university members
// AGGREGATION: Department HAS a collection of UniversityMember pointers
//              The members exist independently - if the Department is destroyed,
//              the actual Student/Staff/TA objects are NOT destroyed with it
// POLYMORPHIC COLLECTION: We store base class pointers so we can mix
//                         Students, Staff, and TAs in the same array
class Department
{
private:
    string departmentName;          // Name of this department (e.g., "Computer Science")
    UniversityMember* members[50];  // Array of pointers to members (AGGREGATION)
                                    // Can hold up to 50 members of any type
    int memberCount;                // Tracks how many members have been added so far

public:
    // Constructor - sets the department name and initializes count to 0
    Department(string departmentName);

    // Adds a university member (Student, Staff, or TA) to this department
    void addMember(UniversityMember* member);

    // Loops through all members and calls displayRole() on each pointer
    // Due to run-time polymorphism, the correct overridden version is called
    // automatically based on the actual object type (Student, Staff, or TA)
    void displayAllRoles();
};

#endif