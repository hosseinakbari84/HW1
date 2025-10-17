#pragma once
#include <string>
#include <vector>
class Order;
class Student
{
public:
    std::string name;
    int studentID;
    std::vector<int> ordersID;
    Student* nextStudent = nullptr;
    std::string getName() const;
    Student(std::string n, int id);
    int getID() const;
    void setName(const std::string &n);
    void setID(int id);
    void printStudentOrders() const;
};