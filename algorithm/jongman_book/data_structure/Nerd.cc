// 처음 풀이. 잘못된 방법 - (2,2), (2,4), (1,3)을 넣는 경우만 생각해도 에러 ㅜㅠ

#include <stdio.h>
#include <stdlib.h>

int number_of_test_case;
int number_of_people;
int problem[100001];
int ramen[100001];
int answer;

struct Node {
    int problem;
    int ramen;
    Node *left;
    Node *right;
};

Node *newNode(int problem, int ramen) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->problem = problem;
    new_node->ramen = ramen;
    new_node->left = nullptr;
    new_node->right = nullptr;
}

int compareNode(Node *node1, Node *node2) {
    // node1과 node2를 사전식 순서로 비교. node1이 node2 보다 크면 1, 작으면 -1, 같으면 0을 return
    if (node1->problem > node2->problem) {
        return 1;
    } else if (node1->problem < node2->problem) {
        return -1;
    } else {
        if (node1->ramen > node2->ramen) return 1;
        else if (node1->ramen < node2->ramen) return -1;
    }

    return 0;
}

void freeTree(Node *root) {
    if (root->left != nullptr) {
        freeTree(root->left);
    }
    if (root->right != nullptr) {
        freeTree(root->right);
    }

    free(root);
}

Node *insertNode(Node *root, Node *node, bool &success) {
    if (root ==  nullptr) {
        success = true;
        return node;
    }

    if (compareNode(root, node) == 1) {
        if (node->problem < root->problem && node->ramen < root->ramen) {
            free(node);
            return root;
        }
        root->left = insertNode(root->left, node, success);
    } else if (compareNode(root, node) == -1) {
        root->right = insertNode(root->right, node, success);
        if (node->problem > root->problem && node->ramen > root->ramen) success = false;
    }

    return root;
}

int sumOfPlayers(Node *root) {
    bool success;
    int sum = 1;
    int current_number = 1;

    for (int i=1; i < number_of_people; ++i) {
        Node *node = newNode(problem[i],ramen[i]);
        success = false;
        insertNode(root, node, success);
        if (success) current_number++;
        sum += current_number;
    }

    return sum;
}

int main() {    
    scanf("%d", &number_of_test_case);

    for (int i=0; i < number_of_test_case; ++i) {
        scanf("%d", &number_of_people);
        
        for (int j=0; j < number_of_people; ++j) {
            scanf("%d %d", &problem[j], &ramen[j]);
        }

        Node *root = newNode(problem[0], ramen[0]);
        answer = sumOfPlayers(root);
        freeTree(root);
        printf("%d\n", answer);
    }

    return 0;
}



