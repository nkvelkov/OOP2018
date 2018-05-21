#include <iostream>
#include <cstring>
#include "CyclicList.h"
#include "Employee.h"
#include <cassert>

using namespace std;

typedef void (*func) ( int);
void f1 ( int a)
{
    cout << "f1 " << a << endl;;
}

void f2 ( int a)
{
    cout << "f2 " << a << endl;;
}

void traverseString(char* str, int curPos)
{
    if (curPos < 0)
    {
        cout << endl;
        return;
    }

    cout << str[curPos] << " ";

    traverseString(str, curPos - 1);

}

void traverseStringPrinting(char* str, int curPos)
{
    if (curPos < 0)
    {
        cout << endl;
        return;
    }

    traverseStringPrinting(str, curPos - 1);

    cout << str[curPos] << " ";

}

void traverseStringReplacing(char* str, int curPos)
{
    if (curPos < 0)
    {
        cout << endl;
        return;
    }

    if (str[curPos] == 'b') {
        str[curPos] = 'h';
    } else if (str[curPos] == 's')
    {
        str[curPos] = 'v';
    } else if (str[curPos] == 'm'){
        str[curPos] = 't';
    }

    traverseStringReplacing(str, curPos - 1);

    cout << str[curPos] << " ";

}

void execute(bool flag, int arg, func f1, func f2)
{
   if (flag)
   {
       f1(arg);
   } else {
       f2(arg);
   }
}



int main()
{
    Employee manager, worker;;
    manager = worker;
    worker = manager;
    assert (Employee::getNumEqualities() == 2 );

    CyclicList cl;

    assert(0 == cl.size());
    cout << cl << endl;

    cl.addAtBeginning(6);
    assert(1 == cl.size());
    cout << cl << endl;

    cl.addAtBeginning(64);
    cout << cl << endl;

    assert(2 == cl.size());

    cl.addToEnd(7);

    assert(3 == cl.size());
    cout << cl << endl;

    cl.removeAtBeginning();

    assert(2 == cl.size());

    cout << cl << endl;

    CyclicList cl2(cl);
    cout << cl2 << endl;
    cout << cl.size()  << " " << cl2.size() << endl;
    assert(cl.size() == cl2.size());

    CyclicList cl3;
    cl3 = cl2;

    assert(cl3.size() == cl2.size());
    assert(cl.size() == cl2.size());
    cout << cl3 << endl;

    char str[124];
    strcpy (str,  "balsama");
    traverseString(str , strlen(str ) - 1);
    traverseStringPrinting(str , strlen(str ) - 1);
    traverseStringReplacing(str , strlen(str ) - 1);

    execute(true, 5, f1, f2);
    execute(false, 6, f1, f2);


    return 0;
}
