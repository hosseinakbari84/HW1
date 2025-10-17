#include "SearchSTD.h"
void getStudentIdAndPrintOrders() {
    int studentID;
    std::cout << "Enter Student ID: ";
    std::cin >> studentID;
    Student* student = studentsList.findStudentByID(studentID);
    if (student) {
        student->printStudentOrders();
    } else {
        std::cout << "Student with ID " << studentID << " not found." << std::endl;
    }
}

void getStudentNameAndPrintOrders() {
    std::string studentName;
    std::cout << "Enter Student name: ";
    std::cin >> studentName;
    Student* student = studentsList.findStudentByName(studentName);
    if (student) {
        student->printStudentOrders();
    } else {
        std::cout << "Student with name " << studentName << " not found." << std::endl;
    }
}