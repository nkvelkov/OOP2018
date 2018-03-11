#include "Disk.h"

using namespace std;

DISK::DISK()
{
   _capacity = 0;
   _usedSpace = 0;
   _partitionLayout = (PARTITION_LAYOUT)0;
   _numberPartitions = 0;
   _diskController = (DISK_CONTROLLER)0;
}

DISK::DISK(unsigned int capacity,
           unsigned int usedSpace,
           PARTITION_LAYOUT layout,
           unsigned int numPartitions,
           DISK_CONTROLLER controller)
{
   _capacity = capacity;
   _usedSpace = usedSpace;
   _partitionLayout = layout;
   _numberPartitions = numPartitions;
   _diskController = controller;
}

unsigned int
DISK::getCapacity() const
{
   return _capacity;
}

unsigned int
DISK::getUsedSpace() const
{
   return _usedSpace;
}

PARTITION_LAYOUT
DISK::getPartitionLayout() const
{
   return _partitionLayout;
}

unsigned int
DISK::getNumPartitions() const
{
   return _numberPartitions;
}

DISK_CONTROLLER
DISK::getDiskController() const
{
   return _diskController;
}

void
DISK::setCapacity(unsigned int capacity)
{
   _capacity = capacity;
}

void
DISK::setUsedSpace(unsigned int usedSpace)
{
   _usedSpace = usedSpace;
}

void
DISK::setPartitionLayout(PARTITION_LAYOUT layout)
{
   _partitionLayout = layout;
}

void
DISK::setDiskController(DISK_CONTROLLER controller)
{
   _diskController = controller;
}

// 1 b)
void
DISK::Read ()
{
  cin >> _capacity >> _usedSpace;
  int numericValue;

  cin >> numericValue;
  _partitionLayout = (PARTITION_LAYOUT)numericValue;

  cin >> _numberPartitions;

  cin >> numericValue;
  _diskController = (DISK_CONTROLLER)numericValue;
}

void
DISK::Write () const
{
  cout << "disk capacity: " << _capacity << endl;
  cout << "disk used space: " << _usedSpace << endl;
  if (_partitionLayout == MBR) {
     cout << "disk partition layout: is MBR" <<  endl;
  } else {
     cout << "disk partition layout: is GPT" <<  endl;
  }
  cout << "number of partitions " << _numberPartitions << endl;

  if (_diskController == IDE) {
     cout << "IDE controller "<< endl;
  } else if (_diskController == SATA ) {
     cout << "SATA controller " << endl;
  } else if (_diskController == SCSI) {
     cout << "SCSI controller" << endl;
  }
}
