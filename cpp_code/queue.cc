#include "queue.h"

int Queue::pop() {
    Node *head = datas_.head();
    int data = head->data();
    datas_.removeHead();
    return data;
}

void Queue::insert(int data) {
    Node *node = new Node(data);
    datas_.insert(node);
}

void Queue::printElements() {
    datas_.printList();
}