#pragma once
#include <string>

class Student
{
protected:
    std::string name;
    int studentID;

public:
    Student(std::string n, int id);
};