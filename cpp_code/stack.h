#include "linked_list.h"

class Stack {
public:
int pop();
int top();
void insert(int data);
bool empty();
private:
LinkedList datas_;
};