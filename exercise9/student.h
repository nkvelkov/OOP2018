#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student
{
    char _facNum[10];
    char _name[30];
    char _faculty[30];
    int _startYear;
public:
    Student(char* facNum, char* name, char* faculty, int startYear);
    void print();
};

#endif // STUDENT_H_INCLUDED
