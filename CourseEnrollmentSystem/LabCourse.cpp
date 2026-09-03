#include "LabCourse.h"

using namespace std;

LabCourse::LabCourse(int code, string name, string instructorName, int capacity, int enrolled)
    : Course(code, name, instructorName, capacity, enrolled) {}

void LabCourse::addCorequisite(int code) {
    corequisiteCodes.push_back(code);
}

const vector<int>& LabCourse::getCorequisites() const {
    return corequisiteCodes;
}

void LabCourse::display() const {
    Course::display();
    cout << "Corequisite Courses: ";
    if (corequisiteCodes.empty()) {
        cout << "None";
    } else {
        for (size_t i = 0; i < corequisiteCodes.size(); i++) {
            cout << corequisiteCodes[i];
            if (i < corequisiteCodes.size() - 1) {
                cout << ", ";
            }
        }
    }
    cout << endl;
}
