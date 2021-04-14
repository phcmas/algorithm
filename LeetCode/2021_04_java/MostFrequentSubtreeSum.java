import java.util.ArrayList;
import java.util.HashMap;

/** 508. Most Frequent Subtree Sum */
/** Given the root of a tree, you are asked to find the most frequent subtree sum. 
 *  The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at 
 *  that node (including the node itself). So what is the most frequent subtree sum value? 
 *  If there is a tie, return all the values with the highest frequency in any order.
 * 
 *  Examples 1
 *  Input:
 *    5
 *   /  \
 *  2   -3
 *  return [2, -3, 4], since all the values happen only once, return all of them in any order.
 * 
 *  Examples 2
 *  Input:
 *    5
 *   /  \
 *  2   -5
 *  return [2], since 2 happens twice, however -5 only occur once.
 *  Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer. */

import java.util.Map;
import java.util.stream.IntStream;
import java.util.List;

public class MostFrequentSubtreeSum {
    private Map<Integer, Integer> hashTable;

    private int setHashTable(TreeNode root) {
        int left = 0;
        int right = 0;
        int curValue = 0;

        if (root == null) return 0;
        
        left = setHashTable(root.left);
        right = setHashTable(root.right);

        curValue = root.val+left+right;
        if (hashTable.containsKey(curValue)) {
            hashTable.replace(curValue, hashTable.get(curValue)+1);
        } else {
            hashTable.put(curValue, 1);
        }

        return curValue;
    }

    public int[] findFrequentTreeSum(TreeNode root) {
        List<Integer> answer = new ArrayList<>();
        int maxCount = Integer.MIN_VALUE;

        hashTable = new HashMap<>();
        setHashTable(root);

        for (Map.Entry<Integer, Integer> entry : hashTable.entrySet()) {
            Integer treeSum = entry.getKey();
            Integer count = entry.getValue();

            if (count > maxCount) {
                answer.clear();
                answer.add(treeSum);
                maxCount = count;
            } else if (count == maxCount) {
                answer.add(treeSum);
            }
        }

        return answer.stream().mapToInt(i->i).toArray();
    }
}