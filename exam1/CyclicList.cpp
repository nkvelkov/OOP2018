#include "CyclicList.h"
#include <cassert>

CyclicList::CyclicList()
   : _last(NULL)
   , _numElements(0)
{

}

CyclicList::CyclicList(const CyclicList& other)
   : _last(NULL)
   , _numElements(0)
{
   copyList(other);
}

CyclicList& CyclicList::operator = (const CyclicList& other)
{
   if (this != &other)
   {
      deleteList();
      assert(_numElements == 0);
      copyList(other);
   }

   return *this;
}

CyclicList::~CyclicList()
{
   deleteList();
}

void CyclicList::addAtBeginning(int data)
{
   Node* newNode = new Node();
   newNode->data = data;
   ++_numElements;

   if (NULL == _last)
   {  // There is no element, so make the new one last
      _last = newNode;
      _last->link = _last;
      return;
   }

   // There is at least one element
   Node* nextNode = _last->link;
   _last->link = newNode;
   newNode->link = nextNode;

}

void CyclicList::addToEnd(int data)
{
   addAtBeginning(data);
   _last = _last->link;
}

void CyclicList::addBeforeLast(int data)
{
   Node* newNode = new Node();
   newNode->data = data;
   ++_numElements;

   if (NULL == _last)
   {  // There is no element, so make the new one last
      _last = newNode;
      _last->link = _last;
      return;
   }

   // There is at least one element

   Node* curNode = _last->link;
   while (curNode->link != _last)
   {
      curNode = curNode->link;
   }

   curNode->link = newNode;
   newNode->link = _last;
}

void CyclicList::removeAtBeginning()
{
   if (_last == NULL)
   {
       return;
   }

   if (_last == _last->link)
   {  // There is only one element
      delete _last;
      _last = NULL;
      --_numElements;
      return;
   }

   // There are at least  2 elements
   Node* firstNode = _last->link;
   Node* secondNode = firstNode->link;

   _last->link = secondNode;

   delete firstNode;
   firstNode = NULL;
   --_numElements;
}

int CyclicList::getSize() const
{
   return _numElements;
}

void CyclicList::copyList(const CyclicList& other)
{
   if (other._last == NULL)
   {
       // The list is empty
       return;
   }

   // Copy the last element
   _last = new Node();
   _last->data = other._last->data;
   ++_numElements;

   Node* prevNode = _last;
   Node* curNode = other._last->link;

   while (curNode != other._last)
   {
       Node* newNode = new Node();
       newNode->data = curNode->data;
       ++_numElements;

       prevNode->link = newNode;

       prevNode = newNode;

       curNode = curNode->link;
   }

   // This covers the case in which there is only one element.
   prevNode->link = _last;

}

void CyclicList::deleteList()
{
   if (_last == NULL)
   {
      return;
   }

   Node* curPtr = _last->link;

   while (curPtr != _last)
   {
       Node* temp = curPtr;

       curPtr = curPtr->link;

       delete temp;
       temp = NULL;
       --_numElements;
   }

   // If there is only one element we won't get inside the loop
   delete _last;
   _last = NULL;
   --_numElements;
}

int CyclicList::size() const
{
   return getSize();
}

ostream& operator << (ostream& out, const CyclicList& list)
{
   if (list._last == NULL)
   {
      out << "EMPTY LIST" << endl;
      return out;
   }

   Node* curNode = list._last->link;

   while (curNode != list._last)
   {
      out << curNode->data << " ";
      curNode = curNode->link;
   }

   // Print the last element
   out << curNode->data << endl;
   return out;
}

istream& operator >> (istream& in, CyclicList& list)
{
    int data;
    while (in >> data)
    {
       list.addToEnd(data);
    }

    return in;
}
