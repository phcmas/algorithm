#ifndef _STACK_
#define _STACK_
#include "linked_list.h"

class Stack {
public:
Stack();
Stack(int data); 
~Stack();
int pop();
int top();
void insert(int data);
bool empty();
private:
LinkedList datas_;
};

#endif
