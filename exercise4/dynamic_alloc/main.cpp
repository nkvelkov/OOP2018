#include "Student.h"
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

Student::Student()
   : _fn(0), _name(NULL)
{
    cout << "Student()" << endl;
}

Student::Student(const char* name, int fn)
   : _fn(fn), _name(NULL)
{
   assert(name);

   cout << "In Student(const char* , int)" << endl;

   setName(name);
}

Student::Student (const Student& right)
{
   cout << " Student(const Student&) " << endl;

   assert(right._name);

   setName(right._name);

   this->_fn = right._fn;
}

/*Student&
Student::operator=(const Student& right)
{
    cout << "Student::operator = " << endll;
}*/

Student::~Student()
{
    cout << "~Student()" << endl;
    delete [] _name;
    _name = NULL;
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

   delete [] _name;

   _name = new char[strlen(name)+1];

   strcpy(_name, name);
}

