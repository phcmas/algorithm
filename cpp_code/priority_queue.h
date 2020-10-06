#include <vector>
#include <iostream>

class PriorityQueue {
public:
PriorityQueue();
~PriorityQueue();
void insert(int data);
int pop();
void swap (int idx0, int idx1);

private:
  std::vector<int> datas_;
};