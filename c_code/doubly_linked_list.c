#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *tail;

void addFront(Node *root, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    Node *next = root->next;
    node->data = data;
    node->prev = root;
    node->next = next;
    root->next = node;
    next->prev = node;
}

void removeFront(Node *root) {
    Node *cur = root->next;
    Node *next = cur->next;
    root->next = next;
    next->prev = root;
    free(cur);
}

void show() {
    Node *cur = head->next;
    while (cur != tail) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node *)malloc(sizeof(Node));
    tail = (Node *)malloc(sizeof(Node));
    head->prev = tail;
    tail->next = head;
    Node *cur = head;
    addFront(head,3);
    cur = cur->next;
    addFront(cur,2);
    removeFront(cur);
    addFront(cur,4);
    cur= cur->next;
    addFront(cur,5);
    cur = cur->next;
    cur->next=tail;
    tail->prev= cur;
    show();
    return 0;





}












