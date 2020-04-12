#include "stack.h"

int Stack::pop() {
    int data = datas_.tail()->data();
    datas_.removeTail();
    return data;
}
int Stack::top() {
    int data = datas_.tail()->data();
    return data;
}

void Stack::insert(int data) {
    Node *node = new Node(data);
    datas_.insert(node);
}

bool Stack::empty() {
    return datas_.head() == nullptr;
}