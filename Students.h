#pragma once
#include "Student.h"
#include <vector>
class Students{
    public:
    Student* head = nullptr;
    void addStudent(Student* newStudent);
    Student* findStudentByID(int studentID);
    Student* findStudentByName(const std::string& name);
};