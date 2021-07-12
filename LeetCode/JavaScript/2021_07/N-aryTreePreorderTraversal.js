/** 589. N-ary Tree Preorder Traversal */
/** Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
 *  Nary-Tree input serialization is represented in their level order traversal. 
 *  Each group of children is separated by the null value (See examples)
 * 
 *  Example 1:
 *  Input: root = [1,null,3,2,4,null,5,6]
 *  Output: [1,3,5,6,2,4]
 * 
 *  Example 2:
 *  Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 *  Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 *  
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 10^4].
 *  0 <= Node.val <= 10^4
 *  The height of the n-ary tree is less than or equal to 1000.
 * 
 *  Follow up: Recursive solution is trivial, could you do it iteratively? */


var preorderTraversal = function(root, nums) {
    if (root == null) return;
    
    nums.push(root.val);

    if (root.children == null) return;

    for (let i = 0; i < root.children.length; ++i) {
        preorderTraversal(root.children[i], nums);
    }
};

var preorder = function(root) {
    var nums = [];
    preorderTraversal(root, nums);
    return nums;
};

var node05 = {val:5, children : null};
var node06 = {val:6, children : null};
var node03 = {val:3, children :[node05, node06]};
var node02 = {val:2, children : null};
var node04 = {val:4, children : null};
var node01 = {val:1, children : [node03, node02, node04]};

var ans0 = preorder(node01);
var ans1 = 1;