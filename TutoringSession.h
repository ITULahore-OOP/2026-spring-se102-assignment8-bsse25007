#ifndef TUTORINGSESSION_H
#define TUTORINGSESSION_H

#include "TeachingAssistant.h"
#include "Student.h"

// TutoringSession represents a single tutoring meeting between a TA and a Student
// ASSOCIATION: This class does NOT own the TA or Student objects -
//              it just holds pointers to them. The TA and Student exist
//              independently and can be part of many sessions.
class TutoringSession
{
private:
    int sessionID;              // Unique ID for this tutoring session
    double durationMinutes;     // How long this session lasted in minutes
    TeachingAssistant* ta;      // Pointer to the TA running this session (ASSOCIATION)
    Student* student;           // Pointer to the student being tutored (ASSOCIATION)

public:
    // Constructor - links an existing TA and Student together for this session
    TutoringSession(int sessionID, double durationMinutes,
                    TeachingAssistant* ta, Student* student);

    // Returns how long this session lasted
    double getDuration() const;

    // Displays all details about this tutoring session
    void displaySession();

    // MEMBER OPERATOR OVERLOADING: + operator
    // Merges two sessions into one by adding their durations together
    // The new session keeps the TA and Student from the left-hand side session
    TutoringSession operator+(const TutoringSession& other);
};

// NON-MEMBER OPERATOR OVERLOADING: > operator
// Compares two sessions and returns true if s1 is longer than s2
// Declared outside the class 
bool operator>(TutoringSession s1, TutoringSession s2);

#endif