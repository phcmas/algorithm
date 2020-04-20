#include "binary_tree.h"

BinaryTree::BinaryTree() {
    data_ = -1;
    height_ = 0;
    left_ = nullptr;
    right_ = nullptr;
} 

BinaryTree::BinaryTree(int data) {
    data_ = data;
    left_ = nullptr;
    right_ = nullptr;
}

BinaryTree::~BinaryTree() {}
int BinaryTree::data() { return data_; }
int BinaryTree::height() { return height_; }
BinaryTree *BinaryTree::left() { return left_;}
BinaryTree *BinaryTree::right() { return right_; }
void BinaryTree::set_data(int data) { data_ = data; }
void BinaryTree::set_left(BinaryTree *left) { left_ = left;}
void BinaryTree::set_right(BinaryTree *right) { right_ = right; }
void BinaryTree::set_height(int height) { height_ = height;}
bool BinaryTree::has_children() { return left_ != nullptr || right_!=nullptr; }
bool BinaryTree::has_left() { return left_ != nullptr; }
bool BinaryTree::has_right() { return right_ != nullptr; }

