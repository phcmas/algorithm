#include <stdio.h>
#define MAX_SIZE 1001

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node **a;
int n,m, c[MAX_SIZE];

void addFront(Node *root, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    root->next = node->next;
    node->next = root;   
}

void dfs (int data) {
    if (c[data]) return;
    c[data] = 1;
    printf("%d ", a[data]->data);
    Node *current = a[data]->next;
    while (current ! = NULL) {
        dfs(current->data);
        current = current->next;
    }
}

int main (void) {
    a = (Node **)malloc(sizeof(Node*)* MAX_SIZE);
    scanf("%d", &m);
    for (int i=0; i < n; ++i) {
        a[i] = (Node *)malloc(sizeof(Node));
    }

    for (int i=0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }

    dfs(1);
    system('pause');
}


