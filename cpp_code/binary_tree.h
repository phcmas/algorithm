#include <iostream>

class BinaryTree {
public:
BinaryTree();
~BinaryTree();
BinaryTree *left();
BinaryTree *right();
void set_left(BinaryTree *left);
void set_right(BinaryTree *right);

private:
BinaryTree *left_;
BinaryTree *right_;
};
