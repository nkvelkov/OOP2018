#ifndef COMPUTER_H_INCLUDED
#define COMPUTER_H_INCLUDED

#include "DISK.h"

const int OS_NAME_MAX_LEN = 11;
const int MAX_NUM_DISKS = 20;

class Computer
{
   public:

       Computer();

       Computer(unsigned int memory,
                unsigned int numNics,
                const char*  name,
                int          numDisks,
                const DISK*  disks);

       unsigned int getMemory() const;
       unsigned int getNumNics() const;
       const char*  getOsName() const;
       int          getNumDisks() const;
       const DISK*  getDisks() const;

       void setMemory(unsigned int memory);
       void setNumNics(unsigned int numNics);
       void setOsName(const char* osName);

       void setDisks(int numDisks, const DISK* disks);

       unsigned int getFreeSpace () const;

   private:
        // Data members
        unsigned int _memory;
        unsigned int _numNics;
        char         _osName[OS_NAME_MAX_LEN];
        int          _numDisks;
        DISK         _disks[MAX_NUM_DISKS];

};




#endif // COMPUTER_H_INCLUDED
