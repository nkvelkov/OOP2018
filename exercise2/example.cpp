#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int const MAX_LEN = 100;

struct Example
{
    char symbol;
    int *ptr;
    char *stringPtr;
    char str[MAX_LEN];
};

int main()
{
    Example dataHolder, copyHolder;

    dataHolder.symbol = 's';

    int number = 3;
    dataHolder.ptr = &number;

    char dataHolderStr[] = "dataHolder dynamic string";
    dataHolder.stringPtr = dataHolderStr;

    strcpy(dataHolder.str, "dataHolder static string");

    copyHolder = dataHolder;

    cout << "dataHolder: " << endl;
    cout << "symbol: " << dataHolder.symbol << endl;
    cout << "*ptr: " << *(dataHolder.ptr) << endl;
    cout << "stringPtr: " << dataHolder.stringPtr << endl;
    cout << "str: " << dataHolder.str << endl << endl;

    cout << "copyHolder: " << endl;
    cout << "symbol: " << copyHolder.symbol << endl;
    cout << "*ptr: " << *(copyHolder.ptr) << endl;
    cout << "stringPtr: " << copyHolder.stringPtr << endl;
    cout << "str: " << copyHolder.str << endl << endl;

    cout << "Performing mutation on copyHolder ... " << endl << endl;

    *(copyHolder.ptr) = 2;
    strncpy(copyHolder.stringPtr, "copy", 4);
    /*
    Calling strncpy(copyHolder.stringPtr, "copy", 4);
    is the same as performing the following 4 assignments:

    copyHolder.stringPtr[0] = 'c';
    copyHolder.stringPtr[1] = 'o';
    copyHolder.stringPtr[2] = 'p';
    copyHolder.stringPtr[3] = 'y';*/

    cout << "dataHolder: " << endl;
    cout << "symbol: " << dataHolder.symbol << endl;
    cout << "*ptr: " << *(dataHolder.ptr) << endl;
    cout << "stringPtr: " << dataHolder.stringPtr << endl;
    cout << "str: " << dataHolder.str << endl << endl;

    cout << "copyHolder: " << endl;
    cout << "symbol: " << copyHolder.symbol << endl;
    cout << "*ptr: " << *(copyHolder.ptr) << endl;
    cout << "stringPtr: " << copyHolder.stringPtr << endl;
    cout << "str: " << copyHolder.str << endl;

    return 0;
}
