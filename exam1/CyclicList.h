#ifndef CYCLICLIST_H_INCLUDED
#define CYCLICLIST_H_INCLUDED

#include <iostream>
using namespace std;

struct Node {
   int   data;
   Node* link;
};

class CyclicList
{
public:
    CyclicList();
    CyclicList(const CyclicList& other);
    CyclicList& operator = (const CyclicList& other);
    ~CyclicList();

    void addAtBeginning(int data);
    void addToEnd(int data);
    void addBeforeLast(int data);
    void removeAtBeginning();

    int getSize() const;
    int size() const;

    friend ostream& operator << (ostream& rhs, const CyclicList& list);
    friend istream& operator >> (istream& rhs, CyclicList& list);

private:
    void copyList(const CyclicList& other);
    void deleteList();

    Node* _last;
    int   _numElements;
};


#endif // CYCLICLIST_H_INCLUDED
