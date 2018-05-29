#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include <cassert>
#include <cstring>

const int NAME_MAX_LEN = 41;

class Doctor {
public:
   Doctor(const char* name, int years)
   {
       assert(name);
       strcpy(_name, name);
       _years = years;
   }

   virtual int getSalary()
   {
      return _years * 2 + 500;
   }

   virtual int testFuncRetType() {

   }

   virtual Doctor* clone()
   {
       return new Doctor(*this);
   }
   virtual ~Doctor()
   {

   }

private:
   char _name[NAME_MAX_LEN];
   int  _years;
};

#endif // DOCTOR_H_INCLUDED
