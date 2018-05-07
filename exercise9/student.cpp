#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(char* facNum, char* name, char* faculty, int startYear)
{
    strcpy(_facNum, facNum);
    strcpy(_name, name);
    strcpy(_faculty, faculty);
    _startYear = startYear;
}

void Student::print()
{
    cout << "Fac. No: " << _facNum << endl;
    cout << "Name: " << _name << endl;
    cout << "Faculty: " << _faculty << endl;
    cout << "Start year: " << _startYear << endl;
}
