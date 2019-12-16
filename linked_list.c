#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node * head;

void addFront (Node *root, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root) {
    Node *cur = root->next;
    root->next = cur->next;
    free(cur);
}

void freeAll() {
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll() {
    Node *cur = head->next;
    while (cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    head = (Node *)malloc(sizeof(Node));
    Node *cur = head->next;
    addFront(head, 1);
    addFront(head,2);
    cur = cur->next;
    addFront(head,3);
    removeFront(cur->next);
    showAll();
    freeAll();
    return 0;
}
