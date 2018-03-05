## Упражнение 2 - Класове и обекти

## Задача 1
Да се реализира клас ```robot```, който да има следните член данни - идентификационен номер(цяло число), продуктивност (цяло число), име (низ с големина до 40 символа).
#####
Като се приложи принципа за енкапсулация на данните да се дефинират конструктор по подразбиране, конструктор с параметри (+ параметри по подразбиране).

#####
Да се дефинират също член функции за достъп и функции мутатори (set и get методи).

## Задача за домашно:

Разгледайте следната програма и разберете защо резултатът е такъв. (Hint: кода от програмата по-долу е във файл example.cpp)

```c++
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
```
