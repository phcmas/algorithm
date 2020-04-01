#include "node.h"

Node::Node (int data): data_(data), next_(nullptr) {}
Node::Node() : data_(-1), next_(nullptr) {}
Node *Node::next() {return next_;}
int Node::data() { return data_;}
void Node::set_next(Node *node) { next_ = node;}
void Node::set_data(int data) {data_=data;}