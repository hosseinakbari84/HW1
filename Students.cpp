#include "Students.h"
#include <vector>
void Students::addStudent(Student* newStudent)
{
    if (!head)
    {
        head = newStudent;
    }
    else
    {
        Student* current = head;
        while (current->nextStudent)
        {
            current = current->nextStudent;
        }
        current->nextStudent = newStudent;
    }
}
Student* Students::findStudentByID(int studentID)
{
    Student* current = head;
    while (current)
    {
        if (current->studentID == studentID)
        {
            return current;
        }
        current = current->nextStudent;
    }
    return nullptr;
}

Student* Students::findStudentByName(const std::string& name)
{
    Student* current = head;
    while (current)
    {
        if (current->getName() == name)
        {
            return current;
        }
        current = current->nextStudent;
    }
    return nullptr;
}