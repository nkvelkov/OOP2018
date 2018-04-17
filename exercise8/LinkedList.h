#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
   int  data;
   Node *next;
};

class LinkedList
{
    public:
        LinkedList();
        LinkedList(const LinkedList&);
        LinkedList& operator= (const LinkedList&);
        ~LinkedList();

        bool empty() const;

        int size ( ) const;

        bool getAt (int index, int& result) const;

        void insertAtBeginning (int data);//- добавяне на елемент в началото на списъка

        void insertToEnd (); // - добавяне на елемент в края на списъка

        void insertBefore (int index); //- добавяне на елемент преди даден елемент в списъка

        void insertAfter (int index); // - добавяне на елемент след даден елемент в списъка
        bool removeAt(int index); // - премахване на елемент на дадена позиция в списъка
        void removeBefore(int index);// - премахване на елемент преди даден елемент в списъка
        bool removeAfter (int index);


    private:

       void copyList(const LinkedList&);
       void deleteList();

       Node* lookup(int index) const;

       Node *root;
       int  _size;
};

#endif // LINKEDLIST_H
