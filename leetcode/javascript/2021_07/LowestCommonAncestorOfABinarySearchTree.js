/** 235. Lowest Common Ancestor of a Binary Search Tree */
/** Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *  According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
 *  two nodes p and q as the lowest node in T that has both p and q as descendants 
 *  (where we allow a node to be a descendant of itself).”
 * 
 *  Example 1:
 *  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 *  Output: 6
 *  Explanation: The LCA of nodes 2 and 8 is 6.
 * 
 *  Example 2:
 *  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 *  Output: 2
 *  Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 * 
 *  Example 3:
 *  Input: root = [2,1], p = 2, q = 1
 *  Output: 2
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [2, 10^5].
 *  -10^9 <= Node.val <= 10^9
 *  All Node.val are unique.
 *  p != q
 *  p and q will exist in the BST. */

function TreeNode(val, left, right) {
    var node = {};
    node.val = val;
    node.left = left === undefined ? null : left;
    node.right = right === undefined ? null : right;
    return node;
}

var dfs = function(root, numToParent) {
    if (root.left !== null) {
        numToParent.set(root.left.val, root);
        dfs(root.left, numToParent);
    }
    
    if (root.right !== null) {
        numToParent.set(root.right.val, root);
        dfs(root.right, numToParent);
    }
    
};

var lowestCommonAncestor = function(root, p, q) {
    var numToParent = new Map();
    var node1 = p, node2 = q;
    var parent1 = root, parent2 = root;
    
    if (root.val == p || root.val == q) return root;
    
    dfs(root, numToParent);

    do {
        if (node1 != root.val) parent1 = numToParent.get(node1);
        if (node2 != root.val) parent2 = numToParent.get(node2);
        if (parent1.val == node2) return parent1;
        if (parent2.val == node1) return parent2;
        if (parent1.val == parent2.val) return parent1;

        node1 = parent1.val;
        node2 = parent2.val;
    } while (node1 != root && node2 != root)

    return null;
};


var node03 = TreeNode(3);
var node05 = TreeNode(5);
var node04 = TreeNode(4, node03, node05);
var node00 = TreeNode(0);
var node02 = TreeNode(2, node00, node04);
var node07 = TreeNode(7);
var node09 = TreeNode(9);
var node08 = TreeNode(8, node07, node09);
var node06 = TreeNode(6, node02, node08);

var node11 = TreeNode(1);
var node12 = TreeNode(2, node11);

var node23 = TreeNode(3);
var node25 = TreeNode(5);
var node24 = TreeNode(4, node23, node25);
var node20 = TreeNode(0);
var node22 = TreeNode(2, node20, node24);
var node27 = TreeNode(7);
var node29 = TreeNode(9);
var node28 = TreeNode(8, node27, node29);
var node26 = TreeNode(6, node22, node28);

var ans0 = lowestCommonAncestor(node06, 2, 8);
var ans1 = lowestCommonAncestor(node06, 2, 4);
var ans2 = lowestCommonAncestor(node12, 2, 1);
var ans3 = lowestCommonAncestor(node26, 2, 8);

console.log(ans0); // 6
console.log(ans1); // 2
console.log(ans2); // 2
console.log(ans3); // 6


