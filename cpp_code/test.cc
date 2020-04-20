#include "algorithm.h"
#include "graph.h"

int main(void) {
    BinaryTree *root = new BinaryTree(30);
    algorithm::InsertBinarySearchTree(root,17);
    algorithm::DeleteBinarySearchTree(root,17);
    algorithm::InsertBinarySearchTree(root,48);
    algorithm::InsertBinarySearchTree(root,5);
    algorithm::DeleteBinarySearchTree(root,30);
    algorithm::InsertBinarySearchTree(root,23);
    algorithm::InsertBinarySearchTree(root,37);
    algorithm::InsertBinarySearchTree(root,50);
    algorithm::DeleteBinarySearchTree(root,48);
    algorithm::PrintPreOrder(root);
}