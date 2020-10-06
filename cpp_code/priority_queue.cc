#include "priority_queue.h"

PriorityQueue::PriorityQueue() {}
PriorityQueue::~PriorityQueue() {}
void PriorityQueue::swap(int idx0, int idx1) {
    int temp = datas_[idx0];
    datas_[idx0] = datas_[idx1];
    datas_[idx1] = temp;
}

void PriorityQueue::insert(int data) {
    datas_.push_back(data);
    int index = datas_.size()-1;
    while (index > 0) {
        if (datas_[(index-1)/2] < datas_[index]) {
            swap((index-1)/2, index);
        }
        index = (index-1)/2;
    }
}

int PriorityQueue::pop() {
    int result = datas_[0];
    datas_[0] = datas_.back();
    datas_.pop_back();
    int index = 0;
    while (2*index +1 < datas_.size()) {
        int target = index;
        if (datas_[index] < datas_[2*index +1]) {
            target = 2*index+1;
        } 
        if (datas_[target] < datas_[2*index+2]) {
            target = 2*index+2;
        }
        if (target == index) break;
        swap (target, index);
        index = target;
    }
    return result;
}


