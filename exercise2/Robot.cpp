#include "Robot.h"
#include <iostream>
#include <cassert>
#include <cstring>

Robot::Robot()
{
    _id = 0;
    _productivity = 0;
    _name[0] = '\0'; // or strcpy(_name, "");
}

Robot::Robot(int id, int productivity, const char* name)
{
    assert(name);

    _id = id;
    _productivity = productivity;

    setName(name);
//  setName(name) is the same as the following 2 lines:
//    assert(name);
//    strcpy(_name, name);
}

void
Robot::setId(int id)
{
    _id = id; //same as this->_id = id;
}

void
Robot::setProductivity(int productivity)
{
    _productivity = productivity;
}

void
Robot::setName(const char* name)
{
    assert(name);

    strcpy(_name, name);
}

int
Robot::getId() const
{
    return _id;
}

int
Robot::getProductivity() const
{
   return _productivity;
}

const char*
Robot::getName() const
{
    return _name;
}

void
Robot::Print() const
{
    std::cout << "Robot id:" << _id
              << " productivity: " << _productivity
              << " name " << _name << std::endl;
}
