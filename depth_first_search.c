#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node{
    int index;
    struct Node *next;
} Node;

Node **a;
int n,m, c[MAX_SIZE];

void addFront(Node *root, int index) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void dfs(int index) {
    if (c[index]) return;
    c[index] = 1;
    printf("%d ", a[index]->index);
    Node *cur = a[index]->next;
    while (cur != NULL) {
        int next = cur->index;
        dfs(next);
        cur = cur->next;
    }
}

int main(void) {
    a = (Node **)malloc(sizeof(Node*)*MAX_SIZE);
    scanf("%d %d", &n, &m);
    for (int i =1; i<=n ; ++i) {
        a[i] = (Node *)malloc(sizeof(Node));
    }

    for (int i=1; i<=m; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        addFront(a[x],y);
        addFront(a[y],x);
    }
    dfs(1);
}





