#include "linked_list.h"

int main(void) {
    LinkedList linked_list;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    linked_list.insert(node1);
    linked_list.insert(node2);
    linked_list.insert(node3);
    linked_list.insert(node4);

    linked_list.printList();
    linked_list.remove();
    linked_list.printList();
}