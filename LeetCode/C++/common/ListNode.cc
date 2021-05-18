#include <iostream>
#include "ListNode.h"

ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

namespace util { 
    ListNode *makeLinkedList(vector<int> nums) {
        ListNode *head = nullptr;
        ListNode *prev = nullptr;

        if (nums.empty()) return nullptr;

        head = new ListNode(nums[0]);
        prev = head;

        for (int i = 1; i < nums.size(); ++i) {
            ListNode *newNode = new ListNode(nums[i]);
            prev->next = newNode;
            prev = newNode;
        }

        return head;
    }

    void printList(ListNode *head) { 
        ListNode *iter = head;

        if (head == nullptr) cout << "no element" << endl;

        cout << "[";
        while (iter->next != nullptr) {
            cout << iter->val << ", ";
            iter = iter->next;
        }

        cout << iter->val << "]";
        cout << endl;
    } 
}

int main() {
    vector<int> nums0 {1,3,4,5,1};
    vector<int> nums1 {3,6,4,1,10,22,3,10};
    vector<int> nums2 {4,5,3,6,1,0,1};

    ListNode *ans0 = util::makeLinkedList(nums0);
    ListNode *ans1 = util::makeLinkedList(nums1);
    ListNode *ans2 = util::makeLinkedList(nums2);

    util::printList(ans0);
    util::printList(ans1);
    util::printList(ans2);


}