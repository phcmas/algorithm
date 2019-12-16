#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *bottom;
    Node *top;
} Queue;

Node *head;

void push(Queue *queue, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (queue->top == NULL) {
        queue->top = node;
        queue->bottom = node;
    } else {
    node->next = queue->top;
    queue->top = node;
    }
}

int pop(Queue *queue) {
    if (queue->bottom == NULL) {
        printf("stack underflow");
        return -999;
    } else {
        Node *cur = queue->bottom;
        Node *iter = queue->top;
        int result = cur->data;
        while (iter->next != cur) {
            iter = iter->next;
        }
        queue->bottom = iter;
        free(cur);
        return result;
    }
}

void show(Queue *queue) {
    Node *cur = queue->top;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    Queue queue;
    queue.bottom = NULL;
    queue.top = NULL;
    push(&queue,1);
    push(&queue,2);
    push(&queue,3);
    pop(&queue);
    push(&queue,4);
    pop(&queue);
    printf("%d ",queue.bottom->data);
    printf("%d ",queue.top->data);
}