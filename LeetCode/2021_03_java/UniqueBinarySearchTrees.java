/** 96. Unique Binary Search Trees */
/** Given an integer n, return the number of structurally unique BST's (binary search trees) 
 *  which has exactly n nodes of unique values from 1 to n.
 * 
 *  Example 1:
 *  Input: n = 3
 *  Output: 5
 * 
 *  Example 2:
 *  Input: n = 1
 *  Output: 1
 * 
 *  Constraints:
 *  1 <= n <= 19 */

 public class UniqueBinarySearchTrees {
    int[] cache;

    public int numTrees(int n) {
       cache = new int[20];
       cache[0] = 1;

       for (int i = 1; i <= n; ++i) {
          for (int j = 0; j <= i-1; ++j) {
             cache[i] += cache[j] * cache[i-1-j];
          }
       }

       return cache[n];
    }
 }