/**24. Swap Nodes in Pairs */
/** Given a linked list, swap every two adjacent nodes and return its head.
 *  
 *  Example 1:
 *  Input: head = [1,2,3,4]
 *  Output: [2,1,4,3]
 * 
 *  Example 2:
 *  Input: head = []
 *  Output: []
 * 
 *  Example 3:
 *  Input: head = [1]
 *  Output: [1]
 * 
 *  Constraints:
 *  The number of nodes in the list is in the range [0, 100].
 *  0 <= Node.val <= 100
 *  Follow up: Can you solve the problem without modifying the values in the list's nodes? (i.e., Only nodes themselves may be changed.) */

public class SwapNodesInPairs {
    public ListNode swapPairs(ListNode head) {
        ListNode odd, even, evenHead;

        if (head == null || head.next == null) return head;

        odd = head;
        even = head.next;
        evenHead = head.next;

        while (even != null) {
            ListNode nextOdd = even.next;
            ListNode nextEven = nextOdd == null ? null : nextOdd.next;

            even.next = odd;
            odd.next = nextEven == null ? nextOdd : nextEven;

            even = nextEven;
            odd = nextOdd;
        }

        return evenHead;
    }
}
