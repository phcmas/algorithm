#include "node.h"

class LinkedList {
public:
LinkedList();
void insert(Node *node);
void remove();
void printList();
Node *head();
Node *tail();
private:
Node *head_;
};