/** 92. Reverse Linked List II */
/** Given the head of a singly linked list and two integers left and right where left <= right, 
 *  reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 *  Example 1:
 *  Input: head = [1,2,3,4,5], left = 2, right = 4
 *  Output: [1,4,3,2,5]
 * 
 *  Example 2:
 *  Input: head = [5], left = 1, right = 1
 *  Output: [5]
 * 
 *  Constraints:
 *  The number of nodes in the list is n.
 *  1 <= n <= 500
 *  -500 <= Node.val <= 500
 *  1 <= left <= right <= n
 *  Follow up: Could you do it in one pass? **/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || left == right) return head;

    ListNode *before = nullptr;
    ListNode *after = nullptr;
    ListNode *iter = head;
    int index = 1;

    for (int i = 0; i < left-1; ++i) {
        iter = iter->next;
    }
    before = iter;
    ListNode *cur = iter->next;
    ListNode *next = cur->next;
    ListNode *nextNext = nullptr;

    for (int i = 0; i < right-left; ++i) {
        nextNext = next->next;
        next->next = cur;
        cur = next;
        next = nextNext;
    }

    before->next->next = nextNext;
    nextNext->next = before;

    return head;
}

int main() {
    ListNode *node05 = new ListNode(5);
    ListNode *node04 = new ListNode(4, node05);
    ListNode *node03 = new ListNode(3, node04);
    ListNode *node02 = new ListNode(2, node03);
    ListNode *node01 = new ListNode(1, node02);

    ListNode *node15 = new ListNode(1);

    ListNode *ans0 = reverseBetween(node01, 2, 4);
    ListNode *ans1 = reverseBetween(node15, 1, 1);

    ListNode *iter = ans0;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    } cout << endl; // 1 4 3 2 5

    iter = ans1;
    while (iter != nullptr) {
        cout << iter->val << " ";
        iter = iter->next;
    } cout << endl; // 5

}