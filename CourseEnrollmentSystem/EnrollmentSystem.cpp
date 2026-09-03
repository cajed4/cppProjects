#include "EnrollmentSystem.h"
#include <stdexcept>

using namespace std;

void displayAllCourses(const map<int, Course*>& allCourses) {
    cout << "\n===== ALL AVAILABLE COURSES =====\n" << endl;
    for (const auto& pair : allCourses) {
        pair.second->display();
        cout << "-----------------------------" << endl;
    }
}

void enrollInCourse(int courseCode, 
                   map<int, Course*>& allCourses,
                   map<int, Course*>& completedCourses,
                   map<int, Course*>& enrolledCourses) {
    
    // Check if course exists
    if (allCourses.find(courseCode) == allCourses.end()) {
        throw runtime_error("Course does not exist");
    }
    
    // Check if already enrolled
    if (enrolledCourses.find(courseCode) != enrolledCourses.end()) {
        throw runtime_error("Already enrolled in this course");
    }
    
    Course* course = allCourses[courseCode];
    
    // Check if course is at capacity
    if (course->getEnrolledCount() >= course->getCapacityLimit()) {
        throw runtime_error("Course is at capacity");
    }
    
    // Check corequisites for lab courses
    LabCourse* labCourse = dynamic_cast<LabCourse*>(course);
    if (labCourse) {
        const vector<int>& coreqs = labCourse->getCorequisites();
        for (int coreqCode : coreqs) {
            if (enrolledCourses.find(coreqCode) == enrolledCourses.end()) {
                throw runtime_error("Missing corequisite course: " + to_string(coreqCode));
            }
        }
    }
    
    // Enroll the student
    course->enrollStudent();
    enrolledCourses[courseCode] = course;
    
    cout << "Successfully enrolled in " << course->getCourseName() << endl;
}
