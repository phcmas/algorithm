#include <iostream>

class Node {
public:
 Node (int data);	
 Node();	
 Node *next(); 
 int data(); 
 void set_next(Node *node); 
 void set_data(int data);
private:
 int data_;
 Node *next_;
};
