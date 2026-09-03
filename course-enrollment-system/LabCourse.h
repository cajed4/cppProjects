#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <vector>

class LabCourse : public Course {
private:
    std::vector<int> corequisiteCodes;
    
public:
    // Constructor
    LabCourse(int code, std::string name, std::string instructorName, int capacity, int enrolled = 0);
    
    // Add a corequisite course code
    void addCorequisite(int code);
    
    // Get corequisite course codes
    const std::vector<int>& getCorequisites() const;
    
    // Override display method to include corequisites
    void display() const override;
};

#endif // LABCOURSE_H
