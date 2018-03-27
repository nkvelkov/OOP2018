#include "Student.h"
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

int Student::id = 0;

Student::Student()
   : _fn(0), _namePtr(NULL)
{
    id++;
    _uid = id;
    cout << "Student()" << endl;
    strcpy(_name, "name");
    _namePtr = new char[NAME_MAX_LEN];
    assert(_namePtr);
    strcpy(_namePtr, "name");
}

Student::Student (const Student& right)
{
    id++;
    _uid = id;
    _namePtr = new char[strlen(right._namePtr)+1];

    strcpy(this->_namePtr, right._namePtr);
    strcpy(this->_name, right._name);
    this->_fn = right._fn;
}

Student& Student::operator= (const Student& right)
{
    if (this != &right)
    {
       delete [] _namePtr;
       int n = strlen(right._namePtr) + 1;
       _namePtr = new char[n];

       strcpy(_namePtr, right._namePtr);

       this->_fn = right._fn;

       strcpy(_name, right._name);

       this->_uid = right._uid;
    }

    return *this;
}

Student::~Student()
{
    id--;
    cout << "~Student()" << endl;
    delete [] _namePtr;
    _namePtr = NULL;
}

Student::Student(const char* name, int fn)
   : _fn(fn), _namePtr(NULL)
{
   id++;
   _uid = id;
   cout << "In Student(const char* , int)" << endl;
   setName(name);
   _namePtr = new char[NAME_MAX_LEN];
   assert(_namePtr);
   strcpy(_namePtr, "name");
}

int
Student::getFn() const
{
   return _fn;
}

const char*
Student::getName() const
{
   return _name;
}

void
Student::setFn(int fn)
{
   _fn = fn;
}

void
Student::setName(const char* name)
{
   assert(name);
   assert(strlen(name) < NAME_MAX_LEN);

   strcpy(_name, name);
}

