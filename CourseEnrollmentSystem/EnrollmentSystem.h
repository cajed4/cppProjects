#ifndef ENROLLMENTSYSTEM_H
#define ENROLLMENTSYSTEM_H

#include "Course.h"
#include "LabCourse.h"
#include <map>

// Function to display all courses
void displayAllCourses(const std::map<int, Course*>& allCourses);

// Function to enroll a student in a course
void enrollInCourse(int courseCode, 
                   std::map<int, Course*>& allCourses,
                   std::map<int, Course*>& completedCourses,
                   std::map<int, Course*>& enrolledCourses);

#endif // ENROLLMENTSYSTEM_H
