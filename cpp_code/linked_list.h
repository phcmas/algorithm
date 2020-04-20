#ifndef _LinkedList_
#define _LinkedList_
#include "node.h"

class LinkedList {
public:
LinkedList();
void insert(Node *node);
void removeTail();
void removeHead(); 
void printList();
Node *head();
Node *tail();

private:
Node *head_;
}; 
#endif
