#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED

#include "doctor.h"
#include "nurse.h"
#include "surgeon.h"
#include "dentist.h"

typedef Doctor* DoctorPtr;

class Hospital
{
public:
   Hospital(DoctorPtr *arr, int numDoctors)
    : _arr(NULL)
    , _numDoctors(0)
   {
      _numDoctors = numDoctors;
      _arr = new DoctorPtr[numDoctors];
      for (int i = 0; i < numDoctors; ++i)
      {
          _arr[i] = arr[i]->clone();
      }
   }

   Hospital(const Hospital& hospital)
      : _arr(NULL)
      , _numDoctors(0)
   {
       copyHospital(hospital);
   }

   Hospital& operator = (const Hospital& other)
   {
       if (this != &other)
       {
           deleteHospital();
           copyHospital(other);
       }
       return *this;
   }

   virtual ~Hospital()
   {
       deleteHospital();
   }

   int getDoctorsCount()
   {
       return _numDoctors;
   }

   void addDoctor(const Doctor* doc)
   {
       if (_numDoctors >= _capacity)
       {
           // TODO: extend;
           return;
       }
       _arr[_numDoctors] = doc->clone();
       ++_numDoctors;
   }

   void addDoctor(const Doctor& doc)
   {
       if (_numDoctors >= _capacity)
       {
           // TODO: extend;
           return;
       }
       _arr[_numDoctors] = doc.clone();
       ++_numDoctors;
   }

   void removeDentist(int numPatients)
   {
       for (int i = 0; i < _numDoctors; ++i)
       {
           Dentist* dentist = dynamic_cast<Dentist*>(_arr[i]);
           if (dentist != NULL)
           {
               if (dentist->getNumPatients() < numPatients)
               {
                   delete dentist;

                   for (int j = i; j < _numDoctors - 1; ++j)
                   {
                      _arr[j] = _arr[j+1];
                   }
                   _arr[_numDoctors-1] = NULL;
                   --_numDoctors;
               }
           }
       }
   }

private:

   void copyHospital(const Hospital& other)
   {
       _numDoctors = other._numDoctors;
       _arr = new DoctorPtr[_numDoctors];
       for (int i = 0; i < _numDoctors; ++i)
       {
           _arr[i] = other._arr[i]->clone();
       }
   }

   void deleteHospital()
   {
      for (int i = 0; i < _numDoctors; ++i)
      {
         delete _arr[i];
      }

      delete [] _arr;
   }

   DoctorPtr *_arr;
   int _numDoctors;
   int _capacity;
};

























#endif // HOSPITAL_H_INCLUDED
