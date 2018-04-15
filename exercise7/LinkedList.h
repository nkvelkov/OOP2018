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

        void insertAtBeginning ();//- �������� �� ������� � �������� �� �������

        void insertToEnd (); // - �������� �� ������� � ���� �� �������

        void insertBefore (int index); //- �������� �� ������� ����� ����� ������� � �������

        void insertAfter (int index); // - �������� �� ������� ���� ����� ������� � �������
        void removeAt(int index); // - ���������� �� ������� �� ������ ������� � �������
        void removeBefore(int index);// - ���������� �� ������� ����� ����� ������� � �������
        void removeAfter (int index);


    private:

       void copyList(const LinkedList&);
       void deleteList();
       Node *root;
//       int  size;
};

#endif // LINKEDLIST_H
