#include "Course.h"
#include "LabCourse.h"
#include "EnrollmentSystem.h"
#include <iostream>
#include <map>

// Course Registration System
// By Amare Johnson

using namespace std;

int main() {
    // Create data structures
    map<int, Course*> allCourses;
    map<int, Course*> completedCourses;
    map<int, Course*> enrolledCourses;
    
    // Create some courses
    Course* cs101 = new Course(101, "Intro to Programming", "Dr. Smith", 30, 10);
    Course* cs201 = new Course(201, "Data Structures", "Dr. Johnson", 25, 5);
    Course* cs301 = new Course(301, "Algorithms", "Dr. Williams", 20, 10);
    
    // Create lab courses
    LabCourse* cs101Lab = new LabCourse(102, "Intro to Programming Lab", "Dr. Smith", 30, 8);
    cs101Lab->addCorequisite(101);
    
    LabCourse* cs201Lab = new LabCourse(202, "Data Structures Lab", "Dr. Johnson", 25, 3);
    cs201Lab->addCorequisite(201);
    
    // Add courses to the allCourses map
    allCourses[101] = cs101;
    allCourses[201] = cs201;
    allCourses[301] = cs301;
    allCourses[102] = cs101Lab;
    allCourses[202] = cs201Lab;
    
    // Simulate that student has completed some courses
    completedCourses[101] = cs101;
    
    char choice;
    do {
        cout << "\n===== STUDENT ENROLLMENT SYSTEM =====\n";
        cout << "1. View all courses\n";
        cout << "2. Enroll in a course\n";
        cout << "3. View enrolled courses\n";
        cout << "4. View completed courses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case '1':
                displayAllCourses(allCourses);
                break;
                
            case '2': {
                int code;
                cout << "Enter course code to enroll: ";
                cin >> code;
                
                try {
                    enrollInCourse(code, allCourses, completedCourses, enrolledCourses);
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
                
            case '3': {
                cout << "\n===== ENROLLED COURSES =====\n" << endl;
                if (enrolledCourses.empty()) {
                    cout << "No courses enrolled" << endl;
                } else {
                    for (const auto& pair : enrolledCourses) {
                        pair.second->display();
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            }
                
            case '4': {
                cout << "\n===== COMPLETED COURSES =====\n" << endl;
                if (completedCourses.empty()) {
                    cout << "No courses completed" << endl;
                } else {
                    for (const auto& pair : completedCourses) {
                        pair.second->display();
                        cout << "-----------------------------" << endl;
                    }
                }
                break;
            }
                
            case '5':
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != '5');
    
    return 0;
}
