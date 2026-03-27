#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H

#include <string>
using namespace std;

// Abstract base class for all university members 
// Contains common attributes shared by everyone in the university system
class UniversityMember
{
private:
    string name;     // Name of the university member
    int memberID;    // Unique memberID assigned to each member

public:
    // Constructor to initialize name and memberID
    UniversityMember(string name, int memberID);

    // Virtual destructor cleans up through base class pointers
    virtual ~UniversityMember();

    // Getter for name
    string getName() const;

    // Getter for memberID
    int getMemberID() const;

    // Pure virtual function 
    virtual void displayRole() = 0;
};

#endif