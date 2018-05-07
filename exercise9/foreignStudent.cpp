#include "foreignStudent.h"
#include <iostream>
#include <cstring>
using namespace std;

ForeignStudent::ForeignStudent(char* facNum, char* name, char* faculty, int startYear,
                            char* nationality, int tax, char* address)
                    :Student(facNum, name, faculty, startYear)
{
    strcpy(_nationality, nationality);
    _tax = tax;
    strcpy(_address, address);
}

void ForeignStudent::print()
{
    Student::print();

    cout << "Nationality: " << _nationality << endl;
    cout << "Tax: " << _tax << endl;
    cout << "Address: " << _address << endl;
}
