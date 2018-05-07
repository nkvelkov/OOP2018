#ifndef FOREIGNSTUDENT_H_INCLUDED
#define FOREIGNSTUDENT_H_INCLUDED

#include "Student.h"

class ForeignStudent: public Student
{
    char _nationality[30];
    int _tax;
    char _address[30];
public:
    ForeignStudent(char* facNum, char* name, char* faculty, int startYear,
                   char* nationality, int tax, char* address);
    void print();
};

#endif // FOREIGNSTUDENT_H_INCLUDED
