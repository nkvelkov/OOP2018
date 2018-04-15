#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

const int INITIAL_VEC_SIZE = 1;
template <typename T>
class Vector;

template <typename T>
std::ostream& operator << (std::ostream& out, Vector<T> const& vec)
{
    for (int i = 0; i < vec.size; ++i)
    {
       out << vec[i] << " ";
    }
    out << std::endl;

    return out;
}

template <typename T>
std::istream& operator >>  (std::istream& in, Vector<T>& vec)
{
    int curNumber;
    while (in >> curNumber)
    {
        vec.push_back(curNumber);
    }

    return in;
}

template <typename T>
class Vector
{
    public:

        friend std::ostream& operator << <T> (std::ostream& out, Vector<T> const& vec);
        friend std::istream& operator >> <T> (std::istream& out, Vector<T> & vec);

        Vector() : arr(NULL), size(0), capacity(0)
        {
           arr = new int[INITIAL_VEC_SIZE];
           capacity = INITIAL_VEC_SIZE;
        }

        Vector(const Vector<T>& other)
        {
           copyVector(other);
        }

        Vector<T>& operator= (const Vector<T>& other)
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

        void push_back(T elem)
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

        bool insertAt(int index, T element)
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

        bool elementExists(T element) const
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

        void copyVector(const Vector<T>& other)
        {
           this->arr = new T[other.capacity];
           this->size = other.size;
           this->capacity = other.capacity;

           for (int i = 0; i < size; ++i)
           {
               this->arr[i] = other.arr[i];
           }
        }

        void extendVector()
        {
           T *temp = arr;
           arr = new T[2 * capacity];

           capacity *= 2;

           for (int i = 0; i < size; ++i)
           {
               arr[i] = temp[i];
           }

           delete [] temp;
        }

        T* arr;
        int  size;
        int  capacity;
};

#endif // VECTOR_H_INCLUDED
