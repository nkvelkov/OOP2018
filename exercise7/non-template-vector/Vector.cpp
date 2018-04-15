#include "Vector.h"


ostream& operator << (ostream& out, Vector const& vec)
{
    for (int i = 0; i < vec.size; ++i)
    {
       out << vec[i] << " ";
    }
    out << std::endl;

    return out;
}

istream& operator >> (istream& in, Vector & vec)
{
    int curNumber;
    while (in >> curNumber)
    {
        vec.push_back(curNumber);
    }

    return in;
}


Vector::Vector() : arr(NULL), size(0), capacity(0)
{
   arr = new int[INITIAL_VEC_SIZE];
   capacity = INITIAL_VEC_SIZE;
}

Vector::Vector(const Vector& other)
{
   copyVector(other);
}

Vector& Vector::operator= (const Vector& other)
{
   if (this != &other)
   {
       deleteVector();
       copyVector(other);
   }
   return *this;
}

Vector::~Vector()
{
   deleteVector();
}

void Vector::push_back(int elem)
{
    if (size >= capacity)
    {
       extendVector();
    }

    arr[size] = elem;
    ++size;
}

int Vector::pop_back()
{
    --size;
}

bool Vector::insertAt(int index, int element)
{
    if (index < 0 || index > size)
    {
       return false;
    }

    if (size >= capacity)
    {
        extendVector();
    }

    for (int i = size-1; i > index; --i)
    {
        arr[i+1] = arr[i];
    }

    arr[index] = element;
    ++size;

    return true;
}

bool Vector::removeAt(int index)
{
    if (index < 0 || index > size)
    {
        return false;
    }

    for (int i = index; i < size; ++i)
    {
        arr[i] = arr[i+1];
    }
    --size;

    return true;
}

int& Vector::operator[] (int index)
{
   return arr[index];
}

const int& Vector::operator[] (int index) const
{
   return arr[index];
}

bool Vector::elementExists(int element) const
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

int Vector::getSize () const
{
   return size;
}

bool Vector::empty () const
{
   return size == 0;
}

void Vector::deleteVector()
{
   delete [] arr;
}

void Vector::copyVector(const Vector& other)
{
   this->arr = new int[other.capacity];
   this->size = other.size;
   this->capacity = other.capacity;

   for (int i = 0; i < size; ++i)
   {
      this->arr[i] = other.arr[i];
   }
}

void Vector::extendVector()
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
