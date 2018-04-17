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

        void insertAtBeginning (int data);//- �������� �� ������� � �������� �� �������

        void insertToEnd (); // - �������� �� ������� � ���� �� �������

        void insertBefore (int index); //- �������� �� ������� ����� ����� ������� � �������

        void insertAfter (int index); // - �������� �� ������� ���� ����� ������� � �������
        bool removeAt(int index); // - ���������� �� ������� �� ������ ������� � �������
        void removeBefore(int index);// - ���������� �� ������� ����� ����� ������� � �������
        bool removeAfter (int index);


    private:

       void copyList(const LinkedList&);
       void deleteList();

       Node* lookup(int index) const;

       Node *root;
       int  _size;
};

#endif // LINKEDLIST_H
