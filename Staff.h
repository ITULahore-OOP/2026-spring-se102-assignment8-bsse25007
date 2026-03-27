#ifndef STAFF_H
#define STAFF_H

#include "UniversityMember.h" //Linker used to link files
#include "AccessCard.h"

// Staff class represents a university staff member who earns a salary
// Uses Virtual inheritance from UniversityMember 
// Composition, Staff HAS-AN AccessCard object stored by value
//              When a Staff object is destroyed, its card is destroyed too
class Staff : virtual public UniversityMember
{
private:
    double salary;      // Salary of the staff member
    AccessCard card;    // Composition, Staff Has-a UniversityMember

public:
    // Constructor, passes name and memberID to base class, stores salary and card
    Staff(string name, int memberID, double salary, AccessCard card);

    //Getter
    // Returns the staff member's salary
    double getSalary() const;

    // Overrides the pure virtual function from UniversityMember
    void displayRole() override;

    // Displays info about staff member's access card
    void displayCard();
};

#endif