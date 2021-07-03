/** 897. Increasing Order Search Tree */
/** Given the root of a binary search tree, rearrange the tree in in-order so that 
 *  the leftmost node in the tree is now the root of the tree, 
 *  and every node has no left child and only one right child.
 * 
 *  Example 1:
 *  Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 *  Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 *  Example 2:
 *  Input: root = [5,1,7]
 *  Output: [1,null,5,null,7]
 * 
 *  Constraints:
 *  The number of nodes in the given tree will be in the range [1, 100].
 *  0 <= Node.val <= 1000 */

function TreeNode(val, left, right) {
    var node = {};
    node.val = (val===undefined ? 0 : val)
    node.left = (left===undefined ? null : left)
    node.right = (right===undefined ? null : right)
    return node;
}

var increasingBST = function(root) {
    if (root == null) return null;

    var newLeft;
    var newRight;

    newLeft = increasingBST(root.left);
    newRight = increasingBST(root.right);

    root.left = null;
    root.right = newRight;

    if (newLeft != null) {
        var leftLeaf = newLeft;
        while (leftLeaf.right != null) {
            leftLeaf = leftLeaf.right;
        }

        leftLeaf.right = root;
    } else {
        newLeft = root;
    }
    
    return newLeft;
};

var node01 = TreeNode(1);
var node07 = TreeNode(7);
var node05 = TreeNode(5, node01, node07);
var ans0 = increasingBST(node05);

var node11 = TreeNode(1);
var node12 = TreeNode(2, node11);
var node14 = TreeNode(4);
var node13 = TreeNode(3, node12, node14);
var node17 = TreeNode(7);
var node19 = TreeNode(9);
var node18 = TreeNode(8, node17, node19);
var node16 = TreeNode(6, null, node18);
var node15 = TreeNode(5, node13, node16);
var ans1 = increasingBST(node15);





