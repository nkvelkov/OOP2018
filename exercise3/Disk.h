#ifndef DISK_H_INCLUDED
#define DISK_H_INCLUDED

#include <iostream>

enum PARTITION_LAYOUT { MBR, GPT };
enum DISK_CONTROLLER {IDE, SATA, SCSI};

class DISK {
   public:
      DISK();
      DISK(unsigned int capacity,
           unsigned int usedSpace,
           PARTITION_LAYOUT layout,
           unsigned int numPartitions,
           DISK_CONTROLLER controller);

      unsigned int getCapacity() const;
      unsigned int getUsedSpace() const;
      PARTITION_LAYOUT getPartitionLayout() const;
      unsigned int getNumPartitions() const;
      DISK_CONTROLLER getDiskController() const;

      void setCapacity(unsigned int capacity);
      void setUsedSpace(unsigned int usedSpace);
      void setPartitionLayout(PARTITION_LAYOUT layout);
      void setDiskController(DISK_CONTROLLER controller);

   // 1 b)
   void Read ();

   void Write () const;

   private:
       unsigned int     _capacity;
       unsigned int     _usedSpace;
       PARTITION_LAYOUT _partitionLayout;
       unsigned int     _numberPartitions;
       DISK_CONTROLLER  _diskController;
};

#endif // DISK_H_INCLUDED
