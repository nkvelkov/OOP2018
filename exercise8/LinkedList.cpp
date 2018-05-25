#include "LinkedList.h"
#include <iostream>
#include <cassert>

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
       assert(NULL == root);
       assert(0 == _size);
       copyList(other);
   }
   return *this;
}

LinkedList::~LinkedList()
{
    deleteList();
    assert(NULL == root);
    assert(0 == _size);
}

void
LinkedList::copyList(const LinkedList& other)
{
   Node* otherRoot = other.root;

   if (otherRoot)
   {
       root = new Node();
       root->data = otherRoot->data;
       ++_size;
   } else {
      root = NULL;
      return;
   }

   Node* prevNode = root;

   otherRoot = otherRoot->next;
   while (otherRoot != NULL)
   {
      Node *nextNode = new Node();
      nextNode->data = otherRoot->data;
      prevNode->next = nextNode;
      ++_size;

      prevNode = nextNode;
      otherRoot = otherRoot->next;
   }
   prevNode->next = NULL;
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
       tempNode = NULL;

       --_size;
   }
   root = NULL;
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
    assert(node);

    result = node->data;

    return true;
}

void LinkedList::insertAtBeginning (int data)
{
   Node* newNode = new Node();
   newNode->data = data;
   ++_size;

   newNode->next = root;
   root = newNode;

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
   targetNode = NULL;

   --_size;

   return true;
}

bool LinkedList::removeAt(int index)
{
   if (!root)
   {
      return false;
   }

   if (0 == index)
   {
       Node* curNode = root;
       root = curNode->next;
       delete curNode;
       curNode = NULL;

       --_size;

       return true;
   }

   return removeAfter(index-1);
}

bool LinkedList::empty() const
{
    return 0 == _size;
}

int LinkedList::size ( ) const
{
    return _size;
}

int LinkedList::calculateSize ( ) const
{
    Node* curNode = root;
    int numElements = 0;

    while (curNode != NULL)
    {
        curNode = curNode->next;
        numElements++;
    }

    return numElements;
}

void LinkedList::insertToEnd () // - добавяне на елемент в края на списъка
{
    // TODO: implement me
}

void LinkedList::insertBefore (int index) //- добавяне на елемент преди даден елемент в списъка
{
    // TODO: implement me
}

void LinkedList::insertAfter (int index) // - добавяне на елемент след даден елемент в списъка
{
    // TODO: implement me
}

void LinkedList::removeBefore(int index) // - премахване на елемент преди даден елемент в списъка
{
    // TODO: implement me
}

void LinkedList::print() const
{
    Node* curNode = root;

    while (curNode != NULL)
    {
        std::cout << curNode->data << " ";
        curNode = curNode->next;

    }
    std::cout << std::endl;
}
