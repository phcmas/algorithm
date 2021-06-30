/** 203. Remove Linked List Elements */
/** Given the head of a linked list and an integer val, remove all the nodes of the 
 *  linked list that has Node.val == val, and return the new head.
 * 
 *  Example 1:
 *  Input: head = [1,2,6,3,4,5,6], val = 6
 *  Output: [1,2,3,4,5]
 * 
 *  Example 2:
 *  Input: head = [], val = 1
 *  Output: []
 * 
 *  Example 3:
 *  Input: head = [7,7,7,7], val = 7
 *  Output: []
 * 
 *  Constraints:
 *  The number of nodes in the list is in the range [0, 10^4].
 *  1 <= Node.val <= 50
 *  0 <= val <= 50 */

function ListNode(val, next) {
    var list = {};
    list.val = val === undefined ? 0 : val;
    list.next = next === undefined ? null : next;
    return list;
}

var removeElements = function(head, val) {
    var newHead = {val: -1, next: head};
    var prev = newHead;
    var cur = head;

    if (cur == null) return head;

    while (cur != null) {
        if (cur.val == val) {
            prev.next = cur.next;
            cur = prev.next;
        } else {
            prev = cur;
            cur = cur.next;
        }
    }

    return newHead.next;
};

var node06_1 = ListNode(6);
var node05 = ListNode(5, node06_1);
var node04 = ListNode(4, node05);
var node03 = ListNode(3, node04);
var node06_2 = ListNode(6, node03);
var node02 = ListNode(2, node06_2);
var node01 = ListNode(1, node02);

var ans0 = removeElements(node01, 6);

var a = 1;
