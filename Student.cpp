#include "Student.h"
#include <iostream>
#include "ordersManagement.h"

Student::Student(std::string n, int id) : name(n), studentID(id) {}
std::string Student::getName() const {
    return name;
}
int Student::getID() const {
    return studentID;
}
void Student::setName(const std::string &n) {
    name = n;
}
void Student::setID(int id) {
    if(id < 10000000 || id > 99999999) {
        std::cout << "Invalid student ID. Order not created." << std::endl;
        return;
    }
    studentID = id;
}
void Student::printStudentOrders() const {
    std::cout << "Student Name: " << name << ", ID: " << studentID << std::endl;
    std::cout << "Orders : ";
    for (const auto& orderID : ordersID) {
        ordersList.findOrderByID(orderID)->printOrder();
    }

}