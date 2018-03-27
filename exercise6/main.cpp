#include <iostream>
#include <cstring>
#include "Book.h"
#include "Vector.h"
using namespace std;


int const MAX_LEN = 100;

typedef int NUMBER;
typedef void (*operation) (int);

void
TestOperation(int n)
{
    cout << n << endl;
}

void (*getOperation()) (int n)
{
    return TestOperation;
}

operation
TestArg(operation op)
{
   cout << "in TestArg" << endl;
   op(5);
   return op;
}

void TestOp(int p)
{
    cout << p << endl;
}

int main()
{
    Vector v;
    v.push_back(4);
    cout << v[0] << endl; // same as     v.operator[](0);

    Book book;
    book.setOperation(TestOp);
    book.executeOperation();

    cout << Book::getCurrentObjectCount() << endl;
    Book b1;
    cout << Book::getCurrentObjectCount() << endl;
    cout << b1.getUuid() << endl;

    return 0;
}


















