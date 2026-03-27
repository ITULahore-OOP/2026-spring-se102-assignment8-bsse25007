#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

using namespace std;

int main()
{
    // Create objects
    AccessCard card1("AC-001", 1);
    AccessCard card2("AC-002", 3);
    AccessCard card3("AC-TA1", 2);
    AccessCard card4("AC-TA2", 2);

    Student s1("Alice", 1001, 3.5);
    Student s2("Bob", 1002, 3.8);

    Staff st1("Dr. Ahmed", 2001, 85000.0, card1);
    Staff st2("Prof. Sara", 2002, 95000.0, card2);

    TeachingAssistant ta1("Charlie", 3001, 3.9, 15000.0, card3, 20);
    TeachingAssistant ta2("Diana", 3002, 3.7, 12000.0, card4, 15);

    TutoringSession session1(101, 45.0, &ta1, &s1);
    TutoringSession session2(102, 30.0, &ta1, &s2);

    Department dept("Computer Science");
    dept.addMember(&s1);
    dept.addMember(&s2);
    dept.addMember(&st1);
    dept.addMember(&st2);
    dept.addMember(&ta1);
    dept.addMember(&ta2);

    int choice;

    do
    {
        // MAIN MENU
        cout << "\n========================================" << endl;
        cout << "   ASSIGNMENT 8   " << endl;
        cout << "========================================" << endl;
        cout << "1. Display All Students" << endl;
        cout << "2. Display All Staff" << endl;
        cout << "3. Display All Teaching Assistants" << endl;
        cout << "4. Display Department " << endl;
        cout << "5. Update Student CGPA" << endl;
        cout << "6. Grade Assignment " << endl;
        cout << "7. Display Tutoring Sessions" << endl;
        cout << "8. Compare Sessions using > Operator" << endl;
        cout << "9. Merge Sessions using + Operator" << endl;
        cout << "0. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                // Display all student info
                cout << "\n--- Students ---" << endl;
                s1.displayRole();
                s2.displayRole();
                break;

            case 2:
                // Display all staff info along with their access cards
                cout << "\n--- Staff ---" << endl;
                st1.displayRole();
                cout << "  Card -> ";
                st1.displayCard();
                st2.displayRole();
                cout << "  Card -> ";
                st2.displayCard();
                break;

            case 3:
                // Display all teaching assistant info
                cout << "\n--- Teaching Assistants ---" << endl;
                ta1.displayRole();
                ta2.displayRole();
                break;

            case 4:
                // Run-time polymorphism: base class pointers call correct overridden method
                dept.displayAllRoles();
                break;

            case 5:
            {
                // Let the user pick a student and enter a new CGPA
                int studentChoice;
                double newCGPA;

                cout << "\nSelect Student:" << endl;
                cout << "1. Alice (current CGPA: " << s1.getCGPA() << ")" << endl;
                cout << "2. Bob   (current CGPA: " << s2.getCGPA() << ")" << endl;
                cout << "Enter choice: ";
                cin >> studentChoice;

                cout << "Enter new CGPA: ";
                cin >> newCGPA;

                if (studentChoice == 1)
                {
                    s1.updateCGPA(newCGPA);
                    cout << "Alice's CGPA updated to: " << s1.getCGPA() << endl;
                }
                else if (studentChoice == 2)
                {
                    s2.updateCGPA(newCGPA);
                    cout << "Bob's CGPA updated to: " << s2.getCGPA() << endl;
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }
                break;
            }

            case 6:
            {
                // Compile-time polymorphism: two overloaded versions of gradeAssignment()
                int gradeChoice;

                cout << "\nSelect grading method:" << endl;
                cout << "1. Numeric Score (int)" << endl;
                cout << "2. Letter Grade (string)" << endl;
                cout << "Enter choice: ";
                cin >> gradeChoice;

                if (gradeChoice == 1)
                {
                    int score;
                    cout << "Enter numeric score: ";
                    cin >> score;
                    ta1.gradeAssignment(score);  // calls gradeAssignment(int)
                }
                else if (gradeChoice == 2)
                {
                    string grade;
                    cout << "Enter letter grade: ";
                    cin >> grade;
                    ta1.gradeAssignment(grade);  // calls gradeAssignment(string)
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }
                break;
            }

            case 7:
                // Display both tutoring sessions
                cout << "\n--- Tutoring Sessions ---" << endl;
                session1.displaySession();
                session2.displaySession();
                break;

            case 8:
                // Non-member operator > : compares sessions by duration
                cout << "\n--- Comparing Sessions (> operator) ---" << endl;
                cout << "Session 1 duration: " << session1.getDuration() << " mins" << endl;
                cout << "Session 2 duration: " << session2.getDuration() << " mins" << endl;

                if (session1 > session2)
                {
                    cout << "Session 1 is longer than Session 2." << endl;
                }
                else
                {
                    cout << "Session 2 is longer than or equal to Session 1." << endl;
                }
                break;

            case 9:
            {
                // Member operator + : merges two sessions into one
                cout << "\n--- Merging Sessions (+ operator) ---" << endl;
                cout << "Session 1 duration: " << session1.getDuration() << " mins" << endl;
                cout << "Session 2 duration: " << session2.getDuration() << " mins" << endl;

                TutoringSession merged = session1 + session2;

                cout << "Merged session duration: " << merged.getDuration() << " mins" << endl;
                break;
            }

            case 0:
                cout << "\nExiting... " << endl;
                break;

            default:
                cout << "\nInvalid choice. Please enter a number from the menu." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}