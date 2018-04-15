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

        int getAt (int index) const;

        void insertAtBeginning ();//- добавяне на елемент в началото на списъка

        void insertToEnd (); // - добавяне на елемент в края на списъка

        void insertBefore (int index); //- добавяне на елемент преди даден елемент в списъка

        void insertAfter (int index); // - добавяне на елемент след даден елемент в списъка
        void removeAt(int index); // - премахване на елемент на дадена позиция в списъка
        void removeBefore(int index);// - премахване на елемент преди даден елемент в списъка
        void removeAfter (int index);


    private:

       void copyList(const LinkedList&);
       void deleteList();
       Node *root;
//       int  size;
};

#endif // LINKEDLIST_H
