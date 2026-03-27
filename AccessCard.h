#ifndef ACCESSCARD_H
#define ACCESSCARD_H

#include <string> // To use string datatype
using namespace std;

// AccessCard represents the physical ID card given to staff members
// It stores the card's ID and what level of access it grants 
class AccessCard
{
private:
    string cardID;      //unique cardID
    int accessLevel;    // Level of access this card grants to different building areas

public:
    // Constructor to initialize card ID and access level
    AccessCard(string cardID, int accessLevel);

    //Getters
    // Returns the card's unique ID
    string getCardID() const;

    // Returns the access level of this card
    int getAccessLevel() const;

    // Displays all info about this card
    void displayCardInfo();
};

#endif