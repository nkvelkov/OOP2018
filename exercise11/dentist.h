#ifndef DENTIST_H_INCLUDED
#define DENTIST_H_INCLUDED

class Dentist : virtual public Doctor
{
public:
    Dentist(const char* name, int years, int numPatients)
       : Doctor(name, years)
       , _numPatients(numPatients)
    {

    }

    int getSalary() {
       return 2 * _numPatients + 200;
    }

private:
    int _numPatients;
};

#endif // DENTIST_H_INCLUDED
