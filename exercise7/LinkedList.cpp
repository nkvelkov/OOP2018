#include "LinkedList.h"

LinkedList::LinkedList() : root(NULL), size(0)
{
    //ctor
}

LinkedList::LinkedList(const LinkedList& other) : root(NULL), size(0)
{
   copyList(other);
}

LinkedList& LinkedList::operator= (const LinkedList& other)
{
   if (this != &other)
   {
       deleteList();
       copyList();
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
       root->data = otherRoot.data;
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

bool LinkedList::empty() const
{
    // TODO: implement me;
    return false;
}

int LinkedList::size ( ) const;
{
    // TODO: implement me
}

int LinkedList::getAt (int index) const
{
    // TODO: implement me
    return 0;
}

