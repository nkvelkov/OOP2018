#include "Student.h"
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

Student::Student()
   : _fn(0)
{
    cout << "Student()" << endl;
    strcpy(_name, "name");
}

Student::~Student()
{
    cout << "~Student()" << endl;
}

Student::Student(const char* name, int fn)
   : _fn(fn)
{
   cout << "In Student(const char* , int)" << endl;
   setName(name);
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

