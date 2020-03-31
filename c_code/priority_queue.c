#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    int heap[MAX_SIZE];
    int count;
} priorityQueue;

void push (priorityQueue *pq, int data) {
    pq->heap[pq->count] = data;
    int now = pq->count;
    int parent = (now-1)/2;
    while (pq->heap[now] > pq->heap[parent]) {
        swap (&pq->heap[now],&pq->heap[parent]);
        now = parent;
        parent = (now-1)/2;
    }
    pq->count++;
}

int pop (priorityQueue *pq) {
    int result = pq->heap[0];
    pq->count--;
    swap(&pq->heap[0], &pq->heap[pq->count]);
    int now=0, leftChild=1, rightChild=2;
    int target=now;

    while (leftChild < pq->count) {
        if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
        if (pq->heap[target] < pq->heap[rightChild] && rightChild <pq->count) target = rightChild;
        if (now == target) break;
        else {
            swap(&pq->heap[target], &pq->heap[now]);
            now = target;
            leftChild = now*2+1;
            rightChild =  now*2 +2;
        }
    }
    return result;
}


int main(void) {
    int n, data;
    priorityQueue pq;
    pq.count=0;
    scanf("%d", &n);
    for (int i=0; i<n ; ++i) {
        scanf("%d", &data);
        push(&pq, data);
    }

    for (int i=0; i<n; ++i){
        data = pop(&pq);
        printf("%d ", data);
    }
    return 0;
}
















