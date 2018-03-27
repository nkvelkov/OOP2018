#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED

#include "Student.h"

class Group
{
public:
    // constructors
    Group();
    Group(int numStudents, const Student* arr);

    // copy constructor
    Group(const Group& other);

    // operator =
    Group& operator= (const Group& other);

    // destructor
    ~Group();

    int getNumStudents() const;

    void setStudents(int n, const Student* arr);

private:
    void copyGroup(const Group& other);
    void deleteGroup();

    Student* arr;
    int      numStudents;
};









#endif // GROUP_H_INCLUDED
