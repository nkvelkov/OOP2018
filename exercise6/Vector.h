#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <cstddef>

const int INITIAL_VEC_SIZE = 1;

class Vector
{
    public:
        Vector() : arr(NULL), size(0), capacity(0)
        {
           arr = new int[INITIAL_VEC_SIZE];
           capacity = INITIAL_VEC_SIZE;
        }

        Vector(const Vector& other)
        {
           copyVector(other);
        }

        Vector& operator= (const Vector& other)
        {
           if (this != &other)
           {
               deleteVector();
               copyVector(other);
           }
           return *this;
        }

        ~Vector()
        {
           deleteVector();
        }

        void push_back(int elem)
        {
            if (size >= capacity)
            {
               extendVector();
            }

            arr[size] = elem;
            ++size;
        }

        int pop_back()
        {
            --size;
        }

        bool insertAt(int index, int element)
        {
            if (index < 0 || index > size)
            {
               return false;
            }

            if (size >= capacity)
            {
                extendVector();
            }

            for (int i = size-1; i >= index; --i)
            {
                arr[i+1] = arr[i];
            }

            arr[index] = element;
            ++size;

            return true;
        }

        bool removeAt(int index)
        {
            if (index < 0 || index > size)
            {
                return false;
            }

            for (int i = index; i < size-1; ++i)
            {
                arr[i] = arr[i+1];
            }
            --size;

            return true;
        }

        int& operator[] (int index)
        {
           return arr[index];
        }

        const int& operator[] (int index) const
        {
           return arr[index];
        }

        bool elementExists(int element) const
        {
           for (int i = 0; i < size; ++i)
           {
               if (element == arr[i])
               {
                   return true;
               }
           }
           return false;
        }

        int getSize () const
        {
           return size;
        }

        bool empty () const
        {
           return size == 0;
        }

    private:

        void deleteVector()
        {
           delete [] arr;
        }
        void copyVector(const Vector& other)
        {
           this->arr = new int[other.capacity];
           this->size = other.size;
           this->capacity = other.capacity;

           for (int i = 0; i < size; ++i)
           {
               this->arr[i] = other.arr[i];
           }
        }

        void extendVector()
        {
           int *temp = arr;
           arr = new int[2 * capacity];

           capacity *= 2;

           for (int i = 0; i < size; ++i)
           {
               arr[i] = temp[i];
           }

           delete [] temp;
        }

        int* arr;
        int  size;
        int  capacity;
};

#endif // VECTOR_H
