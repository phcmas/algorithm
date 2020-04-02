#include "linked_list.h"

class Queue {
public:
int pop();
void insert(int data);
void printElements();
private:
LinkedList datas_; 
};