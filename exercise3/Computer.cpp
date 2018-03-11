#include "Computer.h"
#include <cassert>
#include <iostream>
#include <cstring> // strlen

using namespace std;

Computer::Computer()
{

}

Computer::Computer(unsigned int memory,
                   unsigned int numNics,
                   const char*  name,
                   int          numDisks,
                   const DISK*  disks)
{
   assert(name);
   assert(disks);

   _memory = memory;
   _numNics = numNics;

   setOsName(name);

   setDisks(numDisks, disks);
}

unsigned int
Computer::getMemory() const
{
   return _memory;
}

unsigned int
Computer::getNumNics() const
{
   return _numNics;
}

const char*
Computer::getOsName() const
{
   return _osName;
}


int
Computer::getNumDisks() const
{
   return _numDisks;
}

const DISK*
Computer::getDisks() const
{
   return _disks;
}

void
Computer::setMemory(unsigned int memory)
{
   _memory = memory;
}

void
Computer::setNumNics(unsigned int numNics)
{
   _numNics = numNics;
}

void
Computer::setOsName(const char* osName)
{
   assert(osName);
   assert(strlen(osName) < OS_NAME_MAX_LEN);

   strcpy(_osName, osName);
}

void
Computer::setDisks(int numDisks, const DISK* disks)
{
   assert(disks);
   assert(numDisks < MAX_NUM_DISKS);

   _numDisks = numDisks;

   for (int i = 0; i < _numDisks; ++i)
   {
       _disks[i] = disks[i];
   }
}

unsigned int
Computer::getFreeSpace () const
{
   unsigned int result = 0;
   for (int i = 0 ; i < _numDisks; ++i)
   {
       result += _disks[i].getCapacity() - _disks[i].getUsedSpace();
   }

   return result;
}
