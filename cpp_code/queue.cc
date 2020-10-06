#include "queue.h"

Queue::Queue() {}
Queue::Queue(int data) {
    Node *node = new Node(data);
    datas_.insert(node);
}
Queue::~Queue() {}

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

bool Queue::empty() {
    return datas_.head() == nullptr;
}

void Queue::printElements() {
    datas_.printList();
}