/* Evaluate Division */
/** You are given an array of variable pairs equations and an array of real numbers values, 
 *  where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
 *  Each Ai or Bi is a string that represents a single variable.
 * 
 *  You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
 *  Return the answers to all queries. If a single answer cannot be determined, return -1.0.
 *  Note: The input is always valid. 
 *  You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
 * 
 *  Example 1:
 *  Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 *  Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
 *  Explanation: 
 *  Given: a / b = 2.0, b / c = 3.0
 *  queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 *  return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 *  Example 2:
 *  Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 *  Output: [3.75000,0.40000,5.00000,0.20000]
 * 
 *  Example 3:
 *  Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
 *  Output: [0.50000,2.00000,-1.00000,-1.00000]
 * 
 *  Constraints:
 *  1 <= equations.length <= 20
 *  equations[i].length == 2
 *  1 <= Ai.length, Bi.length <= 5
 *  values.length == equations.length
 *  0.0 < values[i] <= 20.0
 *  1 <= queries.length <= 20
 *  queries[i].length == 2
 *  1 <= Cj.length, Dj.length <= 5
 *  Ai, Bi, Cj, Dj consist of lower case English letters and digits. */

package leet_code.java_2021_1;
import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;

public class evaluateDivision {
    HashMap<String, HashMap<String, Double>> graph = new HashMap<>();
    double[] answer;

    private void initialize(List<List<String>> equations, double[] values, int queriesSize) {
        answer = new double[queriesSize];

        for (int i = 0; i < answer.length; ++i) {
            answer[i] = -1;
        }

        for (int i = 0; i < equations.size(); ++i) {
            List<String> equation = equations.get(i);
            String first = equation.get(0);
            String second = equation.get(1);

            if (!graph.containsKey(first)) {
                graph.put(first, new HashMap<>());
            }

            if (!graph.containsKey(second)) {
                graph.put(second, new HashMap<>());
            }

            graph.get(first).put(second, values[i]);
            graph.get(second).put(first, 1/(values[i]));
        }
    }

    private void dfs(String current, String end, int index, double value, HashSet<String> visited) {
        HashMap<String, Double> neighbor;

        if (!graph.containsKey(current)) return;
        neighbor = graph.get(current);
        visited.add(current);

        if (current.equals(end)) {
            answer[index] = value;
            return;
        }

        for (Map.Entry<String, Double> entry : neighbor.entrySet()) {
            String next = entry.getKey();
            double next_value = entry.getValue();

            if (visited.contains(next)) continue;
            dfs(next, end, index, value * next_value, visited);
        }
    }

    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        initialize(equations, values, queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            HashSet<String> visited = new HashSet<>();
            dfs(queries.get(i).get(0), queries.get(i).get(1), i, 1, visited);
        }

        return answer;
    }
}




