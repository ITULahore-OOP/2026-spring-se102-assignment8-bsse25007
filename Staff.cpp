#include "Staff.h"
#include <iostream>
using namespace std;

// Constructor - initializes the base class and stores salary and card
// The card is copied into the Staff object 
Staff::Staff(string name, int memberID, double salary, AccessCard card)
    : UniversityMember(name, memberID), card(card)
{
    this->salary = salary;
}

// Returns the staff member's annual salary
double Staff::getSalary() const
{
    return salary;
}

// Displays this member's role with their salary info
// Called dynamically through base class pointers at runtime
void Staff::displayRole()
{
    cout << "Role: Staff | Name: " << getName() << " | ID: " << getMemberID()
         << " | Salary: " << salary << endl;
}


void Staff::displayCard()
{
    card.displayCardInfo();
}