#include <stdio.h>
#include <stdlib.h>
#define INF 9999999
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
int n,m,c[MAX_SIZE];

void addFront (Node *root, int index) {
    Node *node = (Node *)(malloc(sizeof (Node)));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void queuePush (Queue *queue, int index) {
    Node *node = (Node *)(malloc(sizeof(Node)));
    node->index = index;
    if (queue->count == 0) {
        queue->front = node;
    } else {
        queue->rear->next = node;
    }
    queue->rear = node;
    queue->count++;
}

int queuePop(Queue *queue) {
    if (queue->count == 0) {
        printf("underflow occurs");
        return -INF;
    }
    Node *node = queue->front;
    int result = node->index;
    queue->front = node->next;
    queue->count--;
    free(node);
    return result;
}
void bfs(int start) {
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count = 0;
    queuePush(&queue, start);
    c[start] =1;
    while (queue.count != 0) {
        int result = queuePop(&queue);
        printf("%d", result);
        Node *cur = a[result]->next;
        while (cur != NULL) {
            int next = cur->index;
            if (!c[next]) {
                queuePush(&queue, next);
                c[next] = 1;
            }
            cur = cur->next;
        }
    }
}

 int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node **)(malloc(sizeof (Node *) *MAX_SIZE));
    for (int i=0; i<n; ++i) {
        a[i] = (Node *)(malloc(sizeof(Node)));
        a[i]->next = NULL;
    }
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        addFront(a[x],y);
        addFront(a[y],x);
    }
    bfs(0);

 }




















