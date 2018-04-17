#ifndef STUDENTSTREAM_H_INCLUDED
#define STUDENTSTREAM_H_INCLUDED

#include <iostream>

class StudentStream
{
public:
   StudentStream() : fn(0)
   {
   }

   void setFn(int facNum) {
      fn = facNum;
   }

   operator int () const {
       return fn;
   }

   friend std::ostream& operator << (std::ostream& out, StudentStream const& student);
   friend std::istream& operator >> (std::istream& in, StudentStream& student);
private:
    int fn;
};

#endif // STUDENTSTREAM_H_INCLUDED
