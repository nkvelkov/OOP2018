#ifndef NURSE_H_INCLUDED
#define NURSE_H_INCLUDED

class Nurse : virtual public Doctor
{
public:
    Nurse(const char* name, int years, int numPatients)
       : Doctor(name, years)
       , _numPatients(numPatients)
    {

    }

    virtual int getSalary() {
       return 3 * _numPatients + 100;
    }

   double testFuncRetType(int t) {

   }

private:
    int _numPatients;
};


#endif // NURSE_H_INCLUDED
