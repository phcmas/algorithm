#ifndef _BINARY_TREE_
#define _BINARY_TREE_

class BinaryTree {
public:
BinaryTree();
BinaryTree(int data); 
~BinaryTree();
BinaryTree *left();
BinaryTree *right();
int data();
int height();
void set_data(int data);
void set_left(BinaryTree *left);
void set_right(BinaryTree *right);
void set_height(int height);
void increaseHeight();
bool has_children();
bool has_left();
bool has_right();

private:
int data_;
int height_;
BinaryTree *left_; 
BinaryTree *right_;
};

#endif