﻿Виртуални функции
=================

## Задача 1
Да се реализира клас ```Doctor```. Всеки доктор има:
* име - символен низ с дължина най-много 40 символа.
* стаж - цяло неотрицателно число.
Да се дефинират конструктури, виртуален деструктор и функция
* ``` getSalary ``` - връща стаж * 2 + 500.


Да се реализира клас ```Nurse```, наследяващ ```Doctor```. Всеки санитар има:
* брой пациенти - цяло неотрицателно число.
Да се дефинират конструктури и функция
* ``` getSalary ``` - връща брой пациенти * 3 + 100.


Да се реализира клас ```Dentist```, наследяващ ```Doctor```. Всеки заболекар има:
* брой прегледани пациенти - цяло неотрицателно число.
Да се дефинират конструктури и метод
* ``` getSalary ``` - връща броя на пациентите + 200.


Да се дефинира клас ```Surgeon``` наследяващ от ```Nurse``` и от ```Dentist```. Нека класът има:
* звание - символен низ с дължина най-много 40 символа.
* брой проведени операции
* ``` getSalary ``` - метод, връщащ брой проведени операции * 3 + 1000.
Да се дефинират неоходимите конструктури и методи. Защо деструкторът на ```Doctor``` трябваше да е виртуален?

## Задача 2

Да се дефинира клас ```Hospital``` със следните член данни.
* масив от доктори (това включва санитари, зъболекари и херурзи).  
* addDoctor(const Doctor&) - добавя доктор в масива.
* removeDoctor(int) - премахва докторите, чиято заплата е по-голяма от числото, подадено като аргумент.
* removeDentist(int) - премахва зъболекарите, които са прегледали по-малко пациенти от подаденото като аргумент число. (Hint -> динамично кастване.)
* removeSurgeon(int) - премахва херурзите, които са провели по-малко операции от числото, подадено като аргумент.
* removeNurse(int) - премахва санитарите, чиито брой пациенти е по-малък от числото, подадено като аргумент.