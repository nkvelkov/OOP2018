## Упражнение 2 - Класове и обекти

## Задача 1
Да се реализира клас ```robot```, който да има следните член данни - идентификационен номер(цяло число), продуктивност (цяло число), име (низ с големина до 40 символа).
#####
Като се приложи принципа за енкапсулация на данните да се дефинират конструктор по подразбиране, конструктор с параметри (+ параметри по подразбиране).

#####
Да се дефинират също член функции за достъп и функции мутатори (set и get методи).

## Задача 2
Да се реализира клас ```smartHouse```, в която има роботи - не повече от 20. Нека къщата има също адрес - символен низ до 10 символа, брой стаи, брой хора, живеещи в нея, и брой роботи.

#####
Да се дефинират конструктори, set и get методи.

#####
Да се реализира функция, която сортира роботите по идентификационен номер.

#####
Да се реализира функция, която сортира роботите по продуктивност.

## Задача 3

Копирайте структурите от предишното упражнение и ги превърнете в класове, като приложите принципа за енкапсулация.

## Задача 4

Да се дефинира рекурсивна функция, която променя дадено естествено число като заменя всяко срещане на дадена цифра в него
с друга.

##### 1 a)
Заменянето да се осъществи като се подадат като аргументи два указателя към функции. В случай че цифрата е четна да се използва функцията сочена от първия указател, в противен случай да се ползва другата функция.

##### 1 b)
Заменянето да се осъществи като се извика функция f, която връща указател към функция, правеща самата замяна.
Нека f връща различна функция за всяка различна цифра.

## Задача за домашно:

Разгледайте следната програма и разберете защо резултатът е такъв. (Hint: кода от програмата по-долу е във файл example.cpp)

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
