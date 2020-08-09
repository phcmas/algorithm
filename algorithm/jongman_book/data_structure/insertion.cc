#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std;

int number_of_test_cases;
int size_of_array;

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
    if (root == nullptr) return pair<Node *, Node *> (nullptr, nullptr);

    if (root->data < data) {
        pair<Node *, Node*> rs = split (root->right, data);
        root->setRight(rs.first);
        return pair<Node *, Node *> (root, rs.second);
    }

    pair<Node *, Node *> ls = split(root->left, data);
    root->setLeft(ls.second);
    return pair<Node *,Node *>(ls.first, root);
}

Node *insert (Node *root, Node *node) {
    if (root == nullptr) return node;
    
    

}

void originalSequence() {


}


int main() {



    return 0;
}








