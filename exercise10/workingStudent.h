#ifndef WORKINGSTUDENT_H_INCLUDED
#define WORKINGSTUDENT_H_INCLUDED

#include "Student.h"

class WorkingStudent: public Student
{
    int _salary;
public:
    WorkingStudent(char* facNum, char* name, char* faculty, int startYear, int salary);

    void setSalary(int salary) {_salary = salary;}
    int getSalary() const {return _salary;}

    void print() const;
};

#endif // WORKINGSTUDENT_H_INCLUDED
