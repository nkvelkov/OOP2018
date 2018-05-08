#include "workingStudent.h"
#include <iostream>
#include <cstring>
using namespace std;

WorkingStudent::WorkingStudent(char* facNum, char* name, char* faculty, int startYear, int salary)
                    :Student(facNum, name, faculty, startYear)
{
    setSalary(salary);
}

void WorkingStudent::print() const
{
    Student::print();

    cout << "Salary: " << _salary << endl;
}
