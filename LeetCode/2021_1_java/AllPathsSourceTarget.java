/* 797. All Paths From Source to Target */
/** Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, 
 *  find all possible paths from node 0 to node n - 1, and return them in any order.
 *  The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
 *  (i.e., there is a directed edge from node i to node graph[i][j]).
 *  
 *  Example 1:
 *  Input: graph = [[1,2],[3],[3],[]]
 *  Output: [[0,1,3],[0,2,3]]
 *  Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 *  Example 2:
 *  Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
 *  Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 * 
 *  Example 3:
 *  Input: graph = [[1],[]]
 *  Output: [[0,1]]
 * 
 *  Example 4:
 *  Input: graph = [[1,2,3],[2],[3],[]]
 *  Output: [[0,1,2,3],[0,2,3],[0,3]]
 * 
 *  Example 5:
 *  Input: graph = [[1,3],[2],[3],[]]
 *  Output: [[0,1,2,3],[0,3]]
 * 
 *  Constraints:
 *  n == graph.length
 *  2 <= n <= 15
 *  0 <= graph[i][j] < n
 *  graph[i][j] != i (i.e., there will be no self-loops).
 *  The input graph is guaranteed to be a DAG **/

/* 자바 연습으로 거의 처음 짜봐서 많이 헤맸다 */

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class AllPathsSourceTarget {

    public List<Stack<Integer>> dfs(int[][] graph, int node) {
        List<Stack<Integer>> ret = new ArrayList<>();

        if (node == graph.length-1) {
            Stack<Integer> st = new Stack<Integer>();
            st.push(graph.length-1);
            ret.add(st);
            return ret;
        }

        for (int i = 0; i < graph[node].length; ++i) {
            List<Stack<Integer>> prevRet = dfs(graph, graph[node][i]);

            if (prevRet.isEmpty()) continue;
            for (Stack<Integer> iter : prevRet) {
                iter.push(node);
                ret.add(iter);
            }
        }

        return ret;
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> answer = new ArrayList<>();
        List<Stack<Integer>> ret = dfs(graph, 0);

        for (Stack<Integer> st : ret) {
            List<Integer> path = new ArrayList<>();
            while (!st.isEmpty()) {
                path.add(st.pop());
            }
            answer.add(path);
        }

        return answer;
    } 
}

