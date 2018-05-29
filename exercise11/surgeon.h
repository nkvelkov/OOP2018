#ifndef SURGEON_H_INCLUDED
#define SURGEON_H_INCLUDED

#include "dentist.h"
#include "nurse.h"

class Surgeon : public Nurse, public Dentist
{
public:
    Surgeon(const char* name, int years, int numNursePatients, int numDentPatients, int numSurgeries, const char* degree)
       : Doctor(name, years)
       , Nurse(name, years, numNursePatients)
       , Dentist(name, years, numDentPatients)
       , _numSurgeries(numSurgeries)
    {

        assert(degree);
        strcpy(_degree, degree);
    }

    virtual int getSalary() {
       return 3 * _numSurgeries + 1000;
    }

   double testFuncRetType( int t, int p) {
      cout << "testFuncRetType" << endl;
   }

private:
    char _degree[41];
    int _numSurgeries;
};

#endif // SURGEON_H_INCLUDED
