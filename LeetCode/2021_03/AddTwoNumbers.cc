/* 2. Add Two Numbers */
/** You are given two non-empty linked lists representing two non-negative integers. 
 *  The digits are stored in reverse order, and each of their nodes contains a single digit. 
 *  Add the two numbers and return the sum as a linked list.
 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 *  Example 1:
 *  Input: l1 = [2,4,3], l2 = [5,6,4]
 *  Output: [7,0,8]
 *  Explanation: 342 + 465 = 807.
 * 
 *  Example 2:
 *  Input: l1 = [0], l2 = [0]
 *  Output: [0]
 * 
 *  Example 3:
 *  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *  Output: [8,9,9,9,0,0,0,1]
 * 
 *  Constraints:
 *  The number of nodes in each linked list is in the range [1, 100].
 *  0 <= Node.val <= 9
 *  It is guaranteed that the list represents a number that does not have leading zeros. **/

#include "ListNode.h"
#include <string>
#include <queue>

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr;
    ListNode *node = nullptr;
    bool moreThanTen = false;

    while (l1 != nullptr || l2 != nullptr) {
        int val1 = 0;
        int val2 = 0;

        if (l1 != nullptr) val1 = l1->val;
        if (l2 != nullptr) val2 = l2->val;

        int val = moreThanTen ? val1 + val2 + 1 : val1 + val2;
        moreThanTen = val >= 10;

        ListNode *newNode = new ListNode(val % 10, node);
        if (node != nullptr) node->next = newNode;
        node = newNode;
        if (head == nullptr) head = node;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    if (moreThanTen) {
        ListNode *newNode = new ListNode(1, node);
        if (node != nullptr) node->next = newNode;
        node = newNode;
    }
    node->next = nullptr;

    return head;
}

int main() {
    vector<int> nums01 {2,4,3};
    vector<int> nums02 {5,6,4};
    ListNode *l01 = makeListNode(nums01);

    ListNode *l02 = makeListNode(nums02);
    vector<int> nums11 {0};
    vector<int> nums12 {0};
    ListNode *l11 = makeListNode(nums11);
    ListNode *l12 = makeListNode(nums12);

    vector<int> nums21 {9,9,9,9,9,9,9};
    vector<int> nums22 {9,9,9,9};
    ListNode *l21 = makeListNode(nums21);
    ListNode *l22 = makeListNode(nums22);

    ListNode *ans0 = addTwoNumbers(l01, l02);
    ListNode *ans1 = addTwoNumbers(l11, l12);
    ListNode *ans2 = addTwoNumbers(l21, l22);

    printListNode(ans0); // [7,0,8]
    printListNode(ans1); // [0]
    printListNode(ans2); // [8,9,9,9,0,0,0,1]

    return 0;
}

