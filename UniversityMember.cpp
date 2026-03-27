#include "UniversityMember.h"
#include <iostream>
using namespace std;

// Constructor, sets up the name and memberID for any university member
UniversityMember::UniversityMember(string name, int memberID)
{
    this->name = name;
    this->memberID = memberID;
}

// Virtual destructor, this ensures proper cleanup when deleting 
UniversityMember::~UniversityMember()
{
    // Nothing to manually clean up here since no DMA
}

//Getters
// Returns the name of the university member
string UniversityMember::getName() const
{
    return name;
}

// Returns the member ID
int UniversityMember::getMemberID() const
{
    return memberID;
}