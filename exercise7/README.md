##Упражнение 6 - Приятелски функции. Шаблони. Свързан списък.

###Задача 1

Чрез използване на приятелски функции, да се реализират върху вече дефинирания клас ```Vector```:

* Оператор ```<<```, за извеждане на съдържанието на вектора
* Оператор ```>>```, за въвеждане на съдържанието на вектора

###Задача 2

Да се преправи класа ```Vector```, така че да може да работи с какъвто му се подаде тип, т.е. класа да стане шаблонен.

###Задача 3

Да се дефинира шаблонна структура ```node```, която представлява единична връзка в свързан списък. Тя се характеризира с:

* ```data``` - шаблон
* ```next``` - указател към следваща единична връзка

###Задача 5-1

Да се дефинира шаблонен клас ```LinkedList```, който представлява свързан списък от ```node```s. Операциите, характеризиращи го са:

* ```empty``` - проверка дали списъка е празен
* ```size``` - връща броя на елементите в списъка
* ```getAt``` - връща елемента на дадена позиция
* ```insertAtBeginning``` - добавяне на елемент в началото на списъка
* ```insertToEnd``` - добавяне на елемент в края на списъка
* ```insertBefore``` - добавяне на елемент преди даден елемент в списъка
* ```insertAfter``` - добавяне на елемент след даден елемент в списъка
* ```removeAt``` - премахване на елемент на дадена позиция в списъка
* ```removeBefore``` - премахване на елемент преди даден елемент в списъка
* ```removeAfter``` - премахване на елемент след даден елемент в списъка

За класа да се дефинират конструктори (по подразбиране и за копиране), оператор за присвояване и деструктор.

