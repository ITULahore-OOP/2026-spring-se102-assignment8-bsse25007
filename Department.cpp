#include "Department.h"
#include <iostream>
using namespace std;

// Constructor, sets up the department name and initializes member count to 0 to prevent storing garbage value
Department::Department(string departmentName)
{
    this->departmentName = departmentName;
    memberCount = 0;
}

// Adds a member to the department's array
// The member pointer is used so this is aggregation
void Department::addMember(UniversityMember* member)
{
    // Only add if maximum capacity of 50  isn't exceeded
    if (memberCount < 50)
    {
        members[memberCount] = member;
        memberCount++; //Increment membercount
    }
    else
    { //Print error message
        cout << "Department is full! Cannot add more members." << endl;
    }
}

// Loop through all added members and displays each one's role
// Calling displayRole() triggers the overridden version in the actual derived class. Run-time Polymorphism takes place
void Department::displayAllRoles()
{
    cout << "\n=== Department: " << departmentName << " ===" << endl;
    cout << "Total Members: " << memberCount << endl;
    cout << "------------------------------------" << endl;

    // Loop through each stored pointer and call the virtual function
    for (int i = 0; i < memberCount; i++)
    {
        members[i]->displayRole(); // Virtual decides and picks the right version at runtime
    }

    cout << "------------------------------------" << endl;
}