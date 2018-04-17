#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : root(NULL), _size(0)
{
    //ctor
}

LinkedList::LinkedList(const LinkedList& other) : root(NULL), _size(0)
{
   copyList(other);
}

LinkedList& LinkedList::operator= (const LinkedList& other)
{
   if (this != &other)
   {
       deleteList();
       copyList(other);
   }
   return *this;
}

LinkedList::~LinkedList()
{
    deleteList();
}

void
LinkedList::copyList(const LinkedList& other)
{
   Node* otherRoot = other.root;

   if (otherRoot)
   {
       root = new Node();
       root->data = otherRoot->data;
   } else {
      root = NULL;
      return;
   }

   Node* curNode = root;

   otherRoot = otherRoot->next;
   while (otherRoot != NULL)
   {
      Node *nextNode = new Node();
      nextNode->data = otherRoot->data;
      curNode->next = nextNode;

      curNode = nextNode;
      otherRoot = otherRoot->next;
   }
}

void
LinkedList::deleteList()
{
   Node* curNode = root;
   while (curNode != NULL)
   {
       Node* tempNode = curNode;
       curNode = curNode->next;
       delete tempNode;
   }
}

Node* LinkedList::lookup(int index) const
{
    Node* curNode = root;

    while (curNode != NULL && index > 0)
    {
       curNode = curNode->next;
       --index;
    }

    return curNode;
}

bool LinkedList::getAt (int index, int& result) const
{
    if (index < 0 || index >= _size) {
        return false;
    }

    Node* node = lookup(index);

    result = node->data;

    return true;
}

void LinkedList::insertAtBeginning (int data)
{
   Node* newNode = new Node();
   newNode->data = data;

   newNode->next = root;
   root = newNode;
   ++_size;
}

bool LinkedList::removeAfter (int index)
{
   Node* prevNode = lookup(index);
   if (!prevNode || !prevNode->next)
   {
       return false;
   }

   Node* targetNode = prevNode->next;
   prevNode->next = targetNode->next;

   delete targetNode;

   --_size;

   return true;
}

bool LinkedList::removeAt(int index)
{
   if (index < 1)
   {
       Node* curNode = root;
       root = curNode->next;
       delete curNode;
       --_size;
       return false;
   }

   return removeAfter(index-1);
}

bool LinkedList::empty() const
{
    // TODO: implement me;
    return false;
}

int LinkedList::size ( ) const
{
    Node* curNode = root;
    int elementsCounter = 0;

    while (curNode != NULL)
    {
        curNode = curNode->next;
        elementsCounter++;
    }

    return elementsCounter;
}

