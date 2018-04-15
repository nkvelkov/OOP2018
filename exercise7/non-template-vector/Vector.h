#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <cstddef>
#include <iostream>

using namespace std;

const int INITIAL_VEC_SIZE = 1;
class Vector;

class Vector
{
    public:
        friend ostream& operator << (ostream& out, Vector const& vec);
        friend istream& operator >> (istream& in, Vector & vec);

        Vector();

        Vector(const Vector& other);
        Vector& operator= (const Vector& other);
        ~Vector();
        void push_back(int elem);

        int pop_back();
        bool insertAt(int index, int element);

        bool removeAt(int index);
        int& operator[] (int index);
        const int& operator[] (int index) const;
        bool elementExists(int element) const;
        int getSize () const;
        bool empty () const;

    private:

        void deleteVector();
        void copyVector(const Vector& other);

        void extendVector();
        int* arr;
        int  size;
        int  capacity;
};

#endif // VECTOR_H
