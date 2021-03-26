import java.util.Stack;
import java.util.ArrayDeque;

/** 230. Kth Smallest Element in a BST */
/** Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.
 * 
 *  Example 1:
 *  Input: root = [3,1,4,null,2], k = 1
 *  Output: 1
 * 
 *  Example 2:
 *  Input: root = [5,3,6,2,4,null,null,1], k = 3
 *  Output: 3
 * 
 *  Constraints:
 *  The number of nodes in the tree is n.
 *  1 <= k <= n <= 10^4
 *  0 <= Node.val <= 10^4
 *  
 *  Follow up: If the BST is modified often (i.e., we can do insert and delete operations) 
 *  and you need to find the kth smallest frequently, how would you optimize? */

import java.util.Queue;

public class KthSmallestElementInaBST {
    private void collectTreeNodeInOrder(TreeNode root, Queue<TreeNode> queue) {
        if (root == null) return;
        collectTreeNodeInOrder(root.left, queue);
        queue.add(root);
        collectTreeNodeInOrder(root.right, queue);
    }

    public int kthSmallest(TreeNode root, int k) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        
        collectTreeNodeInOrder(root, queue);
        for (int i = 0; i < k-1; ++i) queue.remove();

        return queue.peek().val;
    }    
}


