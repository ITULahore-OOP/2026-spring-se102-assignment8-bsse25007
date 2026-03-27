#include "TutoringSession.h"
#include <iostream>
using namespace std;

// Constructor - stores session details and links TA and Student via pointers
// Pointers are stored, not copies as this is Association and copies aren't owned 
TutoringSession::TutoringSession(int sessionID, double durationMinutes,
                                 TeachingAssistant* ta, Student* student)
{
    this->sessionID = sessionID;
    this->durationMinutes = durationMinutes;
    this->ta = ta;
    this->student = student;
}

// Returns the duration of this tutoring session in minutes
double TutoringSession::getDuration() const
{
    return durationMinutes;
}

// Prints a detailed summary of this tutoring session
void TutoringSession::displaySession()
{
    cout << "Session ID: " << sessionID
         << " | Duration: " << durationMinutes << " mins"
         << " | TA: " << ta->getName()
         << " | Student: " << student->getName() << endl;
}

// MEMBER OPERATOR OVERLOADING: + operator
TutoringSession TutoringSession::operator+(const TutoringSession& other)
{
    // Add durations together to get total merged session time
    double mergedDuration = this->durationMinutes + other.durationMinutes;

    // Create a new object of TutoringSession and return the merged session with combined duration
    TutoringSession merged(this->sessionID, mergedDuration, this->ta, this->student);
    return merged;
}

// NON-MEMBER OPERATOR OVERLOADING: > operator
// Returns true if session s1 is longer in duration than session s2
// Defined outside the class 
bool operator>(TutoringSession s1, TutoringSession s2)
{
    // Compare durations of both sessions
    if (s1.getDuration() > s2.getDuration())
    {
        return true;
    }
    return false;
}