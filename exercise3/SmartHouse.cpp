#include "SmartHouse.h"
#include <iostream>
#include <cassert> //for assert
#include <cstring>

using namespace std;

SmartHouse::SmartHouse()
{
   cout << "In SmartHouse()" << endl;
   strcpy(_address, ""); // replace with strcpy_s if necessary.
   _numRooms = 0;
   _numPeople = 0;
   _robotsCount = 0;
}

SmartHouse::SmartHouse(const char* address,
                       int numRooms,
                       int numPeople,
                       int robotsCount,
                       const Robot* robots)
{
   cout << "Called SmartHouse(const char*, int, int, int, const Robot*)" << endl;

   assert(address);
   assert(robots);

   setAddress(address);

   _numRooms = numRooms;
   _numPeople = numPeople;

   setRobots(robotsCount, robots);
}

const char*
SmartHouse::getAddress() const
{
   return _address;
}

int
SmartHouse::getNumRooms() const
{
   return _numRooms;
}

int
SmartHouse::getNumPeople() const
{
   return _numPeople;
}

int
SmartHouse::getNumRobots() const
{
   return _robotsCount;
}

const Robot*
SmartHouse::getRobots() const
{
   return _robots;
}

void
SmartHouse::setAddress(const char* address)
{
   assert(address);
   assert(strlen(address) < ADDRESS_MAX_LEN);

   strcpy(_address, address); // replace with strcpy_s if necessary.
}

void
SmartHouse::setNumRooms(int numRooms)
{
   _numRooms = numRooms;
}

void
SmartHouse::setNumPeople(int numPeople)
{
   _numPeople = numPeople;
}

void
SmartHouse::setRobots(int robotsCount, const Robot* robots)
{
   assert(robots);

   _robotsCount = robotsCount;

   for (int i = 0 ; i < _robotsCount; ++i)
   {
       _robots[i] = robots[i];
   }
}

void
SmartHouse::print() const
{
    cout << "Address: " << _address << endl;
    cout << "Num People: " << _numPeople << endl;
    cout << "Num rooms: " << _numRooms << endl;
    cout << "Num robots: " << _robotsCount << endl;

    for (int i = 0; i < _robotsCount; ++i)
    {
        _robots[i].Print();
    }
}

void
SmartHouse::sortById()
{
   // sort by using selection sort
   for (int i = 0; i < _robotsCount-1; ++i)
   {
       int indexMin = i;
       for (int j = i + 1; j < _robotsCount; ++j)
       {
           if (_robots[j].getId() < _robots[indexMin].getId())
           {
               indexMin = j;
           }
       }

       if (indexMin != i)
       {
          Robot temp = _robots[i];
          _robots[i] = _robots[indexMin];
          _robots[indexMin] = temp;
       }
   }
}

void
SmartHouse::sortByProductivity()
{
   // sort by using selection sort
   for (int i = 0; i < _robotsCount-1; ++i)
   {
       int indexMin = i;
       for (int j = i + 1; j < _robotsCount; ++j)
       {
           if (_robots[j].getProductivity() < _robots[indexMin].getProductivity())
           {
               indexMin = j;
           }
       }

       if (indexMin != i)
       {
          Robot temp = _robots[i];
          _robots[i] = _robots[indexMin];
          _robots[indexMin] = temp;
       }
   }
}
