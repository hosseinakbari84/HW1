#pragma once
#include <string>

class Student
{
public:
    std::string name;
    int studentID;

    Student(std::string n, int id);
    std::string getName() const;
    int getID() const;
    void setName(const std::string &n);
    void setID(int id);
};