#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

enum PARTITION_LAYOUT {MBR, GPT};
enum DISK_CONTROLLER {IDE, SATA, SCSI};

struct Disk {
   // Data members
   unsigned int     _capacity;
   unsigned int     _usedSpace;

   PARTITION_LAYOUT _partLayout;
   unsigned int     _numPartitions;

   DISK_CONTROLLER  _diskController;

   // Member functions
   void Read () {
      cin >> _capacity >> _usedSpace;

      unsigned int numericVal;
      cin >> numericVal;
      _partLayout = (PARTITION_LAYOUT)numericVal;

      cin >> _numPartitions;

      cin >> numericVal;
      _diskController = (DISK_CONTROLLER)numericVal;
   }

   void Print () {
      cout << "Capacity is: " << _capacity << ", usedSpace is: " << _usedSpace;
      cout << ", the number of partitions is: " << _numPartitions;

      if (MBR == _partLayout) {
         cout << " MBR " << endl;
      } else if (GPT == _partLayout) {
         cout << " GPT " << endl;
      } else {
         cout << " Unknown partition layout " << endl;
      }

      if (IDE == _diskController) {
         cout << " IDE " << endl;
      } else if (SATA == _diskController) {
         cout << " SATA " << endl;
      } else if (SCSI == _diskController) {
         cout << " SCSI " << endl;
      } else {
         cout << " Unknown disk controller " << endl;
      }
   }
};

const int OS_NAME_MAX_LEN = 11;
const int MAX_NUM_DISKS = 20;

struct Computer
{
   // Data members
   unsigned int _memory;
   unsigned int _numNics;
   char         _osName[OS_NAME_MAX_LEN];
   int          _numDisks;
   Disk         _disks[MAX_NUM_DISKS];

   unsigned int getFreeSpace ()
   {
       unsigned int result = 0;
       for (int i = 0 ; i < _numDisks; ++i)
       {
           result += _disks[i]._capacity - _disks[i]._usedSpace;
       }
       return result;
   }

};

unsigned int computerGetFreeSpace(const Computer& computer)
{
   unsigned int result = 0;
   for (int i = 0 ; i < computer._numDisks; ++i)
   {
       result += computer._disks[i]._capacity - computer._disks[i]._usedSpace;
   }
   return result;
}

int main()
{
    Disk c;

    c.Read();
    c.Print();

    Disk d;

    d.Read();
    d.Print();

    Computer myComputer;

    myComputer._disks[0] = c;
    myComputer._disks[1] = d;
    myComputer._numDisks = 2;

    cout << myComputer.getFreeSpace() << endl;
    cout << computerGetFreeSpace(myComputer) << endl;

    return 0;
}
