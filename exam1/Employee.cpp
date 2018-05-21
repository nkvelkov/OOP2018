#include "Employee.h"
#include <cstring>
#include <cassert>

int Employee::_equalityCounter = 0;

Employee::Employee()
{
   strcpy(_name, "");
   _id = 0;
   _startYear = 0;
}

Employee::Employee(const char* newName, int id, int startYear)
{
   assert(newName);
   setName(newName);
   _id = id;
   _startYear = startYear;
}

bool Employee::operator < (const Employee& other)
{
   return this->_startYear < other._startYear;
}

Employee& Employee::operator = (const Employee& other)
{
   ++_equalityCounter;

   if (this != &other)
   {
      //++_equalityCounter;
      setName(other._name);
      _id = other._id;
      _startYear = other._startYear;
   }

   return *this;
}

const char* Employee::getName() const
{
   return _name;
}

int Employee::getId() const
{
   return _id;
}

int Employee::getStartYear() const
{
   return _startYear;
}

void Employee::setName(const char* newName)
{
   assert(newName);
   assert(strlen(newName) < NAME_MAX_LEN);

   strcpy(_name, newName);
}

void Employee::setId(int id)
{
   _id = id;
}

void Employee::setStartYear(int startYear)
{
   _startYear = startYear;
}

int Employee::getNumEqualities()
{
    return _equalityCounter;
}
