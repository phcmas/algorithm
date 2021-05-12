/** 103. Binary Tree Zigzag Level Order Traversal */
/** Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
 *  (i.e., from left to right, then right to left for the next level and alternate between).
 *  
 *  Example 1:
 *  Input: root = [3,9,20,null,null,15,7]
 *  Output: [[3],[20,9],[15,7]]
 * 
 *  Example 2:
 *  Input: root = [1]
 *  Output: [[1]]
 * 
 *  Example 3:
 *  Input: root = []
 *  Output: []
 *  
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 2000].
 *  -100 <= Node.val <= 100 */

import java.util.*;

public class BinaryTreeZigzagLevelOrderTraversal {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        List<List<Integer>> result = new ArrayList<>();
        int height = -1;

        queue.add(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> values = new ArrayList<>();
            height++;

            for (int i = 0; i < size; ++i) {
                TreeNode cur = queue.poll();
                values.add(cur.val);

                if (cur.left != null) queue.add(cur.left);
                if (cur.right != null) queue.add(cur.right);
            }

            if (height % 2 == 1) Collections.reverse(values);
            result.add(values);
        }

        return result;
    }
}
