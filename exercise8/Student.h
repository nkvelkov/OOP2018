#ifndef Student_H_INCLUDED
#define Student_H_INCLUDED

#include <iostream>

class Student
{
public:
   Student() : fn(0)
   {
   }

   void setFn(int facNum) {
      fn = facNum;
   }

   operator int () {
       return fn;
   }

   friend std::ostream& operator << (std::ostream& out, Student const& student);
   friend std::istream& operator >> (std::istream& in, Student& student);

private:
    int fn;
};

#endif // Student_H_INCLUDED
