/** 530. Minimum Absolute Difference in BST */
/** Given the root of a Binary Search Tree (BST), return the minimum absolute 
 *  difference between the values of any two different nodes in the tree.
 * 
 *  Example 1:
 *  Input: root = [4,2,6,1,3]
 *  Output: 1
 * 
 *  Example 2:
 *  Input: root = [1,0,48,null,null,12,49]
 *  Output: 1
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [2, 10^4].
 *  0 <= Node.val <= 10^5 */

function TreeNode(val, left, right) {
    var node = {};
    node.val = (val===undefined ? 0 : val)
    node.left = (left===undefined ? null : left)
    node.right = (right===undefined ? null : right)
    return node;
}

var getMinimumDifference = function(root) {
    var queue = [];
    var nums = [];
    var answer = Number.MAX_VALUE;
    
    queue.push(root);
    while (queue.length > 0) {
        var node = queue.shift();
        
        for (let i = 0; i < nums.length; ++i) {
            answer = Math.min(answer, Math.abs(node.val - nums[i]));
        }
        
        nums.push(node.val);
        
        if (node.left != null) {
            queue.push(node.left);
        }
        
        if (node.right != null) {
            queue.push(node.right);
        }
        
    }
    
    return answer;
    
};

var node01 = TreeNode(1);
var node03 = TreeNode(3);
var node02 = TreeNode(2, node01, node03);
var node06 = TreeNode(6);
var node04 = TreeNode(4, node02, node06);

var node13 = TreeNode(3);
var node15 = TreeNode(5, node13);
var node11 = TreeNode(1, null, node15);

var ans0 = getMinimumDifference(node04);
var ans1 = getMinimumDifference(node11);

console.log(ans0);
console.log(ans1);
