/** 979. Distribute Coins in Binary Tree */
/** You are given the root of a binary tree with n nodes where each node in the tree has node.val 
 *  coins and there are n coins total.
 *  In one move, we may choose two adjacent nodes and move one coin from one node to another. 
 *  (A move may be from parent to child, or from child to parent.)
 * 
 *  Return the number of moves required to make every node have exactly one coin.
 *  
 *  Example 1:
 *  Input: root = [3,0,0]
 *  Output: 2
 *  Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
 * 
 *  Example 2:
 *  Input: root = [0,3,0]
 *  Output: 3
 *  Explanation: From the left child of the root, we move two coins to the root [taking two moves].  
 *  Then, we move one coin from the root of the tree to the right child.
 * 
 *  Example 3:
 *  Input: root = [1,0,2]
 *  Output: 2
 *  
 *  Example 4:
 *  Input: root = [1,0,0,null,3]
 *  Output: 4
 * 
 *  Constraints:
 *  The number of nodes in the tree is n.
 *  1 <= n <= 100
 *  0 <= Node.val <= n
 *  The sum of Node.val is n. */

// 아래는 잘못된 코드이지만 왠지 지우기 싫어서 놔둠.

import java.util.Queue;
import java.util.Set;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.List;

public class WrongCode {
    private void collectNodes(TreeNode root, List<TreeNode> nodes, Map<TreeNode, TreeNode> parents) {
        Queue<TreeNode> queue = new ArrayDeque<>();

        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode cur = queue.poll();
            nodes.add(cur);

            if (cur.left != null) {
                parents.put(cur.left, cur);
                queue.add(cur.left);
            }

            if (cur.right != null) {
                parents.put(cur.right, cur);
                queue.add(cur.right);
            }
        }
    }

    private void setNeighbor(TreeNode cur, Queue<TreeNode> queue, Set<TreeNode> seen, Map<TreeNode, TreeNode> parents) {
        if (cur.left != null && !seen.contains(cur.left)) {
            queue.add(cur.left);
            seen.add(cur.left);
        }

        if (cur.right != null && !seen.contains(cur.right)) {
            queue.add(cur.right);
            seen.add(cur.right);
        }

        if (parents.containsKey(cur) && !seen.contains(parents.get(cur))) {
            queue.add(parents.get(cur));
            seen.add(parents.get(cur));
        }
    }

    private int distribute(TreeNode node, Map<TreeNode, TreeNode> parents) {
        Queue<TreeNode> queue = new ArrayDeque<>();
        Set<TreeNode> seen = new HashSet<>();
        boolean noCoin = false;
        int coins = node.val;
        int dist = -1;
        int result = 0;

        if (coins <= 1) return 0;
        queue.add(node);

        while (!queue.isEmpty()) {
            int size = queue.size();
            dist++;

            for (int i = 0; i < size; ++i) {
                TreeNode cur = queue.poll();

                if (cur.val == 0) {
                    cur.val = 1;
                    coins--;
                    result += dist;
                }

                if (coins == 1) {
                    noCoin = true;
                    break;
                }

                setNeighbor(cur, queue, seen, parents);
            }

            if (noCoin) break;
        }

        return result;
    }
    
    public int distributeCoins(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<>();
        Map<TreeNode, TreeNode> parents = new HashMap<>();
        int answer = 0;

        collectNodes(root, nodes, parents);

        for (int i = nodes.size()-1; i >= 0; --i) {
            answer += distribute(nodes.get(i), parents);
        }

        for (TreeNode node : nodes) {
            answer += distribute(node, parents);
        }

        return answer;
    }
}

