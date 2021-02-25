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
/* Discussion을 참고하여 다시 구현. Java는 call by value만 있고, call by reference는 없음을 꼭 인지하자
 * (Java는 pointer만 있고 double pointer는 없고, dereferencing해서 클래스를 복사하여 함수의 파라미터로 넘기는 경우는 없다고 이해해도 되는건가??)
 */

import java.util.List;
import java.util.ArrayList;

public class AllPathsSourceTarget2 {
    List<List<Integer>> answer = new ArrayList<>();

    private void dfs (int[][] graph, int node, List<Integer> path) {
        path.add(node);

        if (node == graph.length-1) {
            answer.add(new ArrayList(path));
            return;
        }

        for (int i = 0; i < graph[node].length; ++i) {
            dfs(graph, graph[node][i], path);
            path.remove(path.size()-1);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<Integer> path = new ArrayList<>();
        dfs(graph, 0, path);
        return answer;
    }
}
