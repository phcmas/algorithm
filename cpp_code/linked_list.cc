#include "linked_list.h"

LinkedList::LinkedList() : head_(nullptr) {}
void LinkedList::insert(Node *node) {
    if (head_ == nullptr) {
        head_ = node;
    } else {
        Node *current = head_;
        while (current->next() != nullptr) {
            current = current->next();
        }
        current->set_next(node);
    }
}

void LinkedList::remove() {
    if (head_ == nullptr) return;

    Node *current = head_;
    Node *next = current->next();
    if (next == nullptr) {
        free(head_);
        return;
    }
    while (next->next() != nullptr) {
        current = current->next();
        next = next->next();
    }
    free(next);
    current->set_next(nullptr);
}

void LinkedList::printList() {
    Node *current = head_;
    while (current != nullptr) {
        std::cout << current->data() << " ";
        current = current->next();
    }
    std::cout << std::endl;
}

Node *LinkedList::head() {
    return head_;
}
Node *LinkedList::tail() {
    Node *current = head_;
    while (current->next() != nullptr) {
        current = current->next();
    }
    return current;
}