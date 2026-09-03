#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
using namespace std;

class Course {
protected:
    int courseCode;
    std::string courseName;
    std::string instructor;
    int capacityLimit;
    int enrolledCount;
    
public:
    // Constructor
    Course(int code, string name, string instructorName, int capacity, int enrolled = 0);
    
    // Virtual destructor for proper polymorphic behavior
    virtual ~Course();
            
    // Getters
    int getCourseCode() const;
    string getCourseName() const;
    string getInstructor() const;
    int getCapacityLimit() const;
    int getEnrolledCount() const;
    
    // Setters
    void setEnrolledCount(int count);
    
    // Enroll a student
    void enrollStudent();
    
    // Virtual method to display course info
    virtual void display() const;
};

#endif // COURSE_H
