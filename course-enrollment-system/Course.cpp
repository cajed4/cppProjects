#include "Course.h"
#include <stdexcept>

using namespace std;

Course::Course(int code, string name, string instructorName, int capacity, int enrolled)
    : courseCode(code), courseName(name), instructor(instructorName), 
      capacityLimit(capacity), enrolledCount(enrolled) {}

Course::~Course() {}

int Course::getCourseCode() const { 
    return courseCode; 
}

string Course::getCourseName() const { 
    return courseName; 
}

string Course::getInstructor() const { 
    return instructor; 
}

int Course::getCapacityLimit() const { 
    return capacityLimit; 
}

int Course::getEnrolledCount() const { 
    return enrolledCount; 
}

void Course::setEnrolledCount(int count) { 
    enrolledCount = count; 
}

void Course::enrollStudent() {
    if (enrolledCount >= capacityLimit) {
        throw runtime_error("Course is at capacity");
    }
    enrolledCount++;
}

void Course::display() const {
    cout << "Course Code: " << courseCode << endl
         << "Course Name: " << courseName << endl
         << "Instructor: " << instructor << endl
         << "Capacity: " << capacityLimit << endl
         << "Enrolled: " << enrolledCount << endl;
}
