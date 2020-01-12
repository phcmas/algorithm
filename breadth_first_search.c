#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
    int index;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} Queue;

Node **a;
int n, m, c[MAX_SIZE];

void addFront(Node *root, int index) {
    Node *node =(Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void queuePush (Queue *queue, int index){
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    if (queue->count == 0){
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int queuePop (Queue *queue) {
    if (queue->count == 0) {
        printf("queue underflow");
        return -9999;
    }
    Node *node = queue->front;
    int result = node->index;
    queue->front = node->next;
    free(node);
    queue->count--;
    return result;
}

void bfs(int start) {
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count =0;
    queuePush(&queue, start);
    c[start] = 1;
    while (queue.count != 0) {
        int x = queuePop(&queue);
        printf("%d", x);
        Node *cur = a[x]->next;
        while (cur != NULL) {
            int next = cur->index;
            if (!c[next]) {
                queuePush(&queue, next);
                c[next] =1;
            }
            cur = cur->next;
        }
    }
}

int main(void) {
    
}












