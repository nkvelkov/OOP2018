#include "foreignStudent.h"
#include <iostream>
#include <cstring>
using namespace std;

ForeignStudent::ForeignStudent(char* facNum, char* name, char* faculty, int startYear,
                            char* nationality, int tax, char* address)
                    :Student(facNum, name, faculty, startYear), _nationality(NULL), _address(NULL)
{
    setNationality(nationality);
    setTax(tax);
    setAddres(address);
}

ForeignStudent::ForeignStudent(const ForeignStudent& other)
    :Student(other), _nationality(NULL), _address(NULL)
{
    copyForeignStudent(other);
}

ForeignStudent& ForeignStudent::operator = (const ForeignStudent& other)
{
    if (this != &other)
    {
        Student::operator=(other);
        destroyForeignStudent();
        copyForeignStudent(other);
    }
    return *this;
}

ForeignStudent::~ForeignStudent()
{
    destroyForeignStudent();
}

void ForeignStudent::setNationality(const char* nationality)
{
    if (nationality)
    {
        delete [] _nationality;
        _nationality = new char[strlen(nationality)+1];
        strcpy(_nationality, nationality);
    }
}

void ForeignStudent::setAddres(const char* address)
{
    if (address)
    {
        delete [] _address;
        _address = new char[strlen(address)+1];
        strcpy(_address, address);
    }
}


void ForeignStudent::print() const
{
    Student::print();

    cout << "Nationality: " << _nationality << endl;
    cout << "Tax: " << _tax << endl;
    cout << "Address: " << _address << endl;
}

void ForeignStudent::copyForeignStudent(const ForeignStudent& other)
{
    setNationality(other._nationality);
    setTax(other._tax);
    setAddres(other._address);
}

void ForeignStudent::destroyForeignStudent()
{
    delete [] _nationality;
    delete [] _address;

    _nationality = NULL;
    _address = NULL;
}
