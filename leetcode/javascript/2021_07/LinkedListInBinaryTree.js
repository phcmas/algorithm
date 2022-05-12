/** 1367. Linked List in Binary Tree */
/** Given a binary tree root and a linked list with head as the first node. 
 *  Return True if all the elements in the linked list starting from the head 
 *  correspond to some downward path connected in the binary tree otherwise return False.
 *  In this context downward path means a path that starts at some node and goes downwards.
 * 
 *  Example 1:
 *  Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 *  Output: true
 *  Explanation: Nodes in blue form a subpath in the binary Tree.  
 * 
 *  Example 2:
 *  Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 *  Output: true
 * 
 *  Example 3:
 *  Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 *  Output: false
 *  Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 * 
 *  Constraints:
 *  The number of nodes in the tree will be in the range [1, 2500].
 *  The number of nodes in the list will be in the range [1, 100].
 *  1 <= Node.val <= 100 for each node in the linked list and binary tree. */

function ListNode(val, next) {
    var node = {};
    node.val = (val === undefined ? 0 : val)
    node.next = (next === undefined ? null : next)
    return node;
};
 
function TreeNode(val, left, right) {
    var node = {};
    node.val = (val === undefined ? 0 : val)
    node.left = (left === undefined ? null : left)
    node.right = (right === undefined ? null : right)
    return node;
};

var dfs = function(root, valToNodes) {
    if (root == null) return;
    
    if (valToNodes.has(root.val)) {
        valToNodes.get(root.val).push(root);
    } else {
        valToNodes.set(root.val, [root]);
    }
    
    dfs(root.left, valToNodes);
    dfs(root.right, valToNodes);
    
};

var checkSubPath = function(head, start) {
    if (head == null) return true;
    if (head != null && start == null) return false;
    
    if (head.val == start.val) {
        if (checkSubPath(head.next, start.left)) return true;
        if (checkSubPath(head.next, start.right)) return true;
    } 
    
    return false;
};

var isSubPath = function(head, root) {
    var valToNodes = new Map();
    
    dfs(root, valToNodes);
    
    for (var start of valToNodes.get(head.val)) {    
        if (checkSubPath(head, start)) return true;
    }
    
    return false; 
};

var node01 = TreeNode(1);
var node06 = TreeNode(6);
var node01_2 = TreeNode(1);
var node03 = TreeNode(3);
var node02 = TreeNode(2, node01);
var node08 = TreeNode(8, node01_2, node03);
var node02_2 = TreeNode(2, node06, node08);
var node04 = TreeNode(4, null, node02);
var node04_2 = TreeNode(4, node02_2);
var node01_3 = TreeNode(1, node04, node04_2);

var list08 = ListNode(8);
var list02 = ListNode(2, list08);
var list04 = ListNode(4, list02);

var list16 = ListNode(6);
var list12 = ListNode(2, list16);
var list14 = ListNode(4, list12);
var list11 = ListNode(1, list14);

var list28 = ListNode(8);
var list26 = ListNode(6, list28);
var list22 = ListNode(2, list26);
var list24 = ListNode(4, list22);
var list21 = ListNode(1, list24);

var ans0 = isSubPath(list04, node01_3);
var ans1 = isSubPath(list11, node01_3);
var ans2 = isSubPath(list21, node01_3);

console.log(ans0); // true
console.log(ans1); // true
console.log(ans2); // true
