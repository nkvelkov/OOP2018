#ifndef FOREIGNSTUDENT_H_INCLUDED
#define FOREIGNSTUDENT_H_INCLUDED

#include "Student.h"

class ForeignStudent: public Student
{
    char* _nationality;
    int _tax;
    char* _address;
public:
    ForeignStudent(char* facNum, char* name, char* faculty, int startYear,
                   char* nationality, int tax, char* address);
    ForeignStudent(const ForeignStudent& other);
    ForeignStudent& operator = (const ForeignStudent& other);
    ~ForeignStudent();

    void setNationality(const char* nationality);
    void setTax(int tax) {_tax = tax;}
    void setAddres(const char* address);

    const char* getNationality() const {return _nationality;}
    int getTax() const {return _tax;}
    const char* getAddress() const {return _address;}

    void print() const;
private:
    void copyForeignStudent(const ForeignStudent& other);
    void destroyForeignStudent();
};

#endif // FOREIGNSTUDENT_H_INCLUDED
