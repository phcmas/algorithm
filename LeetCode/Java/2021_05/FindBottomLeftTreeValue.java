/** 513. Find Bottom Left Tree Value */
/** Given the root of a binary tree, return the leftmost value in the last row of the tree.
 * 
 *  Example 1:
 *  Input: root = [2,1,3]
 *  Output: 1
 * 
 *  Example 2:
 *  Input: root = [1,2,3,4,null,5,6,null,null,7]
 *  Output: 7
 * 
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  -2^31 <= Node.val <= 2^31 - 1 */

import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;



public class FindBottomLeftTreeValue {
    public int findBottomLeftValue(TreeNode root) {
        TreeNode leftMost = root;
        Queue<TreeNode> queue = new ArrayDeque<>();

        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            leftMost = queue.peek();

            for (int i = 0; i < size; ++i) {
                TreeNode cur = queue.poll();

                if (cur.left != null) queue.add(cur.left);
                if (cur.right != null) queue.add(cur.right);
            }
            
        }

        return leftMost.val;
    }
}
