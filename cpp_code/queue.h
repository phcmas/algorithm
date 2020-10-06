#ifndef _QUEUE_
#define _QUEUE_
#include "linked_list.h"

class Queue {
public:
Queue();
Queue(int data);
~Queue();
int pop();
void insert(int data);
bool empty(); 
void printElements();
private:
LinkedList datas_; 
};

#endif