#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(char* facNum, char* name, char* faculty, int startYear)
    :_name(NULL), _faculty(NULL)
{
    setFacNum(facNum);
    setName(name);
    setFaculty(faculty);
    setStartYear(startYear);
}

Student::Student(const Student& other)
    :_name(NULL), _faculty(NULL)
{
    copyStudent(other);
}

Student& Student::operator = (const Student& other)
{
    if (this != &other)
    {
        destroyStudent();
        copyStudent(other);
    }
    return *this;
}

Student::~Student()
{
    destroyStudent();
}

void Student::setFacNum(const char* facNum)
{
    if (facNum)
    {
        strcpy(_facNum, facNum);
    }
}

void Student::setName(const char* name)
{
    if (name)
    {
        delete [] _name;
        _name = new char[strlen(name)+1];
        strcpy(_name, name);
    }
}

void Student::setFaculty(const char* faculty)
{
    if (faculty)
    {
        delete [] _faculty;
        _faculty = new char[strlen(faculty)+1];
        strcpy(_faculty, faculty);
    }
}

void Student::print() const
{
    cout << "Fac. No: " << _facNum << endl;
    cout << "Name: " << _name << endl;
    cout << "Faculty: " << _faculty << endl;
    cout << "Start year: " << _startYear << endl;
}

void Student::copyStudent(const Student& other)
{
    setFacNum(other._facNum);
    setName(other._name);
    setFaculty(other._faculty);
    setStartYear(other._startYear);
}

void Student::destroyStudent()
{
    delete [] _name;
    delete [] _faculty;

    _name = NULL;
    _faculty = NULL;
}
