# Course Enrollment System

A multi-file object-oriented course registration system modeling courses, lab courses, and student enrollment.

**Concepts:** OOP (classes, inheritance), `std::map`, pointers, header/implementation file separation

- Models `Course` and `LabCourse` (with corequisite lab sections) as distinct classes
- Tracks all available courses, a student's completed courses, and current enrollment
- Split across `Course`, `LabCourse`, and `EnrollmentSystem` classes with separate headers/implementation files
