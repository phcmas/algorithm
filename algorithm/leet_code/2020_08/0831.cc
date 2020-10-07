#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *deleteLeastUpperBound(TreeNode *root, int &data) {
    if (root->left == nullptr) {
        data = root->val;
        return root->right;
    } else {
        root->left = deleteLeastUpperBound(root->left, data);
    }
    
    return root;
}

TreeNode *deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    if (root->val == key) {
        if (root->left ==  nullptr && root->right ==  nullptr) return nullptr; 
        else if (root->left == nullptr) return root->right;
        else if (root->right == nullptr) return root->left;
        else {
            root->right = deleteLeastUpperBound (root->right, root->val);
        }
    } else if (root->val > key) {
        root->left = deleteNode (root->left, key);
    } else if (root->val < key) {
        root->right = deleteNode (root->right, key);
    }

    return root;
}

int main () {
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(3, node2, node4);
    TreeNode *node6 = new TreeNode(6,nullptr,node7);
    TreeNode *node5 = new TreeNode(5,node3, node6);

    TreeNode *answer = deleteNode(node5,0);

    return 0;
}