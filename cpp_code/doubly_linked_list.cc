#include <iostream>

class Node {
public:
Node (int data): data_(data), prev_(nullptr), next_(nullptr) {}
Node() : data_(-1), prev_(nullptr), next_(nullptr) {}
Node *prev() { return prev_; }
Node *next() { return next_; }
int data() { return data_;}
void set_data(int data) {data_ = data;}
void set_prev(Node *prev) {prev_ = prev;}
void set_next(Node *next) {next_ = next;}
private:
int data_;
Node *prev_;
Node *next_;
};

class DoublyLinkedList {
public:
DoublyLinkedList() : head_(nullptr) {}
void insert(Node *node) {
    if (head_ == nullptr) {
        head_ = node;
    } else {
        Node *current = head_;
        while (current->next() != nullptr) {
            current = current->next();
        }
        current->set_next(node);
        node->set_prev(current);
    }
}
void remove() {
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

void printList() {
    Node *current = head_;
    while (current != nullptr) {
        std::cout << current->data() << " ";
        current = current->next();
    }
    std::cout << std::endl;
}

private:
Node *head_;
};


int main(void) {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    DoublyLinkedList doubly_linked_list;
    doubly_linked_list.insert(node1);
    doubly_linked_list.insert(node2);
    doubly_linked_list.insert(node3);
    doubly_linked_list.insert(node4);

    doubly_linked_list.printList();
    doubly_linked_list.remove();
    doubly_linked_list.printList();
}