#include "Group.h"
#include <iostream>

using namespace std;

// constructors
Group::Group()
   : arr(NULL)
   , numStudents(0)
{
   cout << "Group()" << endl;
}

Group::Group(int numStudents, const Student* arr)
   : arr(NULL), numStudents(numStudents)
{
   cout << "Group(int, Student const *)" << endl;

   this->arr = new Student[numStudents];
   for (int i = 0; i < numStudents; ++i)
   {
       this->arr[i] = arr[i]; // operator = called here
   }
}

// copy constructor
Group::Group(const Group& other)
   : arr(NULL)
{
   cout << "Group(const Group&)" << endl;
   copyGroup(other);
}

// a = a;
// T& p = a;
// a = p;
// operator =
Group& Group::operator= (const Group& other)
{
    cout << "operator= (const Group&)" << endl;

    if (this != &other)
    {
        deleteGroup();
        copyGroup(other);
    }
    return *this;
}

// destructor
Group::~Group()
{
   cout << "~Group()" << endl;
   deleteGroup();
}

void
Group::copyGroup(const Group& other)
{
   this->numStudents = other.numStudents;

   this->arr = new Student[numStudents];
   for (int i = 0; i < numStudents; ++i)
   {
       this->arr[i] = other.arr[i]; // operator = called here
   }
}

void
Group::deleteGroup()
{
   delete [] arr;
   arr = NULL;
}

int
Group::getNumStudents() const
{
   return numStudents;
}

void
Group::setStudents(int n, const Student* arr)
{
   delete [] this->arr;

   this->numStudents = n;
   this->arr = new Student[n];

   for (int i = 0; i < n; ++i)
   {
      this->arr[i] = arr[i]; // operator = called here.
   }
}
