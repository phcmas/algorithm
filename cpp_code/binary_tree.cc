#include "binary_tree.h"

BinaryTree::BinaryTree() {}
BinaryTree::~BinaryTree() {}
BinaryTree *BinaryTree::left() { return left_;}
BinaryTree *BinaryTree::right() { return right_; }
void BinaryTree::set_left(BinaryTree *left) { left_ = left;}
void BinaryTree::set_right(BinaryTree *right) { right_ = right; }