/* 216. Combination Sum III */
/** Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
 *  Only numbers 1 through 9 are used.
 *  Each number is used at most once.
 *  Return a list of all possible valid combinations. The list must not contain the same combination twice, 
 *  and the combinations may be returned in any order.
 * 
 *  Example 1:
 *  Input: k = 3, n = 7
 *  Output: [[1,2,4]]
 *  Explanation:
 *  1 + 2 + 4 = 7
 *  There are no other valid combinations.
 * 
 *  Example 2:
 *  Input: k = 3, n = 9
 *  Output: [[1,2,6],[1,3,5],[2,3,4]]
 *  Explanation:
 *  1 + 2 + 6 = 9
 *  1 + 3 + 5 = 9
 *  2 + 3 + 4 = 9
 *  There are no other valid combinations.
 * 
 *  Example 3:
 *  Input: k = 4, n = 1
 *  Output: []
 *  Explanation: There are no valid combinations. [1,2,1] is not valid because 1 is used twice.
 * 
 *  Example 4:
 *  Input: k = 3, n = 2
 *  Output: []
 *  Explanation: There are no valid combinations.
 * 
 *  Example 5:
 *  Input: k = 9, n = 45
 *  Output: [[1,2,3,4,5,6,7,8,9]]
 *  Explanation:
 *  1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 = 45
 *  ​​​​​​​There are no other valid combinations.
 * 
 *  Constraints:
 *  2 <= k <= 9
 *  1 <= n <= 60 */

package leet_code.java_2021_2;

import java.util.List;
import java.util.ArrayList;

public class CombinationSumIII {
    private void backTracking(List<List<Integer>> answer, List<Integer> list, int k, int current, int number) {
        if (list.size() == k || current == 10) {
            if (list.size() == k && number == 0) {
                List<Integer> newList = new ArrayList<>(list);
                answer.add(newList);
            } 
            return;
        }

        list.add(current);
        backTracking(answer, list, k, current+1, number-current);
        list.remove(list.size()-1);
        
        backTracking(answer, list, k, current+1, number);
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> answer = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        backTracking(answer, list, k, 1, n);
        return answer;
    }
}

