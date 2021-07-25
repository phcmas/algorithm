/** 572. Subtree of Another Tree */
/** Given the roots of two binary trees root and subRoot, 
 *  return true if there is a subtree of root with the same structure 
 *  and node values of subRoot and false otherwise.
 * 
 *  A subtree of a binary tree tree is a tree that consists of a node in tree 
 *  and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
 * 
 *  Example 1:
 *  Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 *  Output: true
 * 
 *  Example 2:
 *  Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 *  Output: false
 * 
 *  Constraints:
 *  The number of nodes in the root tree is in the range [1, 2000].
 *  The number of nodes in the subRoot tree is in the range [1, 1000].
 *  -10^4 <= root.val <= 10^4
 *  -10^4 <= subRoot.val <= 10^4 */

function TreeNode(val, left, right) {
    var node = {};
    node.val = val===undefined ? 0 : val;
    node.left = left===undefined ? null : left;
    node.right = right===undefined ? null : right;

    return node;
}

var isIdentical = function(root1, root2) {
    if (root1 == null && root2 != null) return false;
    if (root1 != null && root2 == null) return false;
    if (root1 == null && root2 == null) return true;
    if (root1.val != root2.val) return false;
    if (!isIdentical(root1.left, root2.left)) return false;
    if (!isIdentical(root1.right, root2.right)) return false;
    
    return true;
};

var dfs = function(root, subRoot) {
    if (root == null) return false;
    if (root.val == subRoot.val && isIdentical(root, subRoot)) return true;
    if (dfs(root.left, subRoot)) return true;
    if (dfs(root.right, subRoot)) return true;
    
    return false;
};

var isSubtree = function(root, subRoot) {
    return dfs(root, subRoot);
};

var node01 = TreeNode(1);
var node02 = TreeNode(2);
var node04 = TreeNode(4, node01, node02);
var node05 = TreeNode(5);
var node03 = TreeNode(3, node04, node05);

var sub01 = TreeNode(1);
var sub02 = TreeNode(2);
var sub04 = TreeNode(4, sub01, sub02);

var node11 = TreeNode(1);
var sub10 = TreeNode(0);

var ans0 = isSubtree(node03, sub04);
var ans1 = isSubtree(node11, sub10);

console.log(ans0); // true
console.log(ans1); // false



