#include <stdio.h>
#include <stdlib.h>
#include <utility>

using namespace std;

int number_of_test_cases;
int size_of_array;
int temp;
int nums[50001];
int answer[50001];

struct Node {
    int data;
    int priority;
    int size;
    Node *left;
    Node *right;
    Node (const int _data) : data(_data), priority(rand()), size(1), left(nullptr), right(nullptr) {}
    void calcSize() { 
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }

    void setLeft(Node *newLeft) { left = newLeft; calcSize();}
    void setRight(Node *newRight) { right = newRight; calcSize();}
};

pair<Node *,Node*> split(Node *root, int data) {
    if (root == nullptr) return pair<Node *, Node*> (nullptr, nullptr);

    if (root->data < data) {
        pair<Node *, Node *> rs = split(root->right, data);
        root->setRight(rs.first);
        return pair<Node *, Node *> (root, rs.second);
    }

    pair<Node *, Node*> ls = split (root->left, data);
    root->setLeft(ls.second);
    return pair<Node *, Node *> (ls.first, root);
}

Node *insert (Node *root, Node *node) {
    if (root == nullptr) return node;

    if (root->priority < node->priority) {
        pair<Node *, Node *> splitted = split(root, node->data);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    } else if (root->data > node->data) {
        root->setLeft(insert(root->left, node));
    } else if (root->data < node->data) {
        root->setRight(insert(root->right, node));
    }

    return root;
}

// max(a) < min (b)
Node *merge (Node *a, Node *b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    
    if (a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    
    a->setRight(merge(a->right,b));
    return a;
}

Node *erase(Node *root, int data) {
    if (root == nullptr) return nullptr;

    if (root->data == data) {
        Node *ret = merge (root->left, root->right);
        delete root;
        return ret;
    } else if (root->data > data) {
        root->setLeft(erase(root->left, data));
    } else {
        root->setRight(erase(root->right,data));
    }

    return root;
}

Node *kth (Node *root, int k) {
    int leftSize = 0;
    if (root->left != nullptr) leftSize = root->left->size;
    if (k <= leftSize) return kth (root->left, k);
    if (k == leftSize+1) return root;
    return kth(root->right, k-leftSize-1);
}

void originalSequence() {
    Node *root = nullptr;
    for (int i=1; i<= size_of_array;++i) {
        Node *node = new Node(i);
        root = insert(root, node);
    }

    for (int i=size_of_array-1 ; i>=0 ; --i) {
        Node *kthNode = kth(root, i-nums[i]+1);
        answer[i] = kthNode->data;
        root = erase (root, kthNode->data);
    }
}

int main() {
    scanf("%d", &number_of_test_cases);

    for (int i=0; i < number_of_test_cases; ++i) {
        scanf("%d", &size_of_array);

        for (int j=0; j < size_of_array; ++j) {
            scanf ("%d", &temp);
            nums[j] = temp;
        }

        originalSequence();
        for (int j=0; j < size_of_array-1; ++j) {
            printf("%d ", answer[j]);
        }

        printf("%d\n", answer[size_of_array-1]);
    }

    return 0;
}





