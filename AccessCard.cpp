#include "AccessCard.h"
#include <iostream>
using namespace std;

// Constructor, sets up the card with its ID and what doors it can open
AccessCard::AccessCard(string cardID, int accessLevel)
{
    this->cardID = cardID;
    this->accessLevel = accessLevel;
}

// Returns the card ID in string datatype
string AccessCard::getCardID() const
{
    return cardID;
}

// Returns the access level in int datatype
int AccessCard::getAccessLevel() const
{
    return accessLevel;
}

// Prints a summary of card's details
void AccessCard::displayCardInfo() 
{
    cout << "Card ID: " << cardID << " | Access Level: " << accessLevel << endl;
}