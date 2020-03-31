#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *cur;

void push(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    cur->next = node;
    node->prev = cur;
    cur = cur->next;
}

int pop() {
    int result = cur->data;
    cur = cur->prev;
    free(cur->next);
    return result;
}

void show () {
    Node *iter = head->next;
    while (iter != cur->next) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
}

int main(void) {
    head = (Node*)malloc(sizeof(Node));
    cur= head;
    push(2);
    push(3);
    push(4);
    pop();
    push(5);
    push(6);
    pop();
    push(7);
    pop();
    push(8);
    show();

}




