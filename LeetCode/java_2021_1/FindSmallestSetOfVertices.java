/* 1557. Minimum Number of Vertices to Reach All Nodes */
/** Given a directed acyclic graph, with n vertices numbered from 0 to n-1, 
 *  and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
 *  Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
 *  Notice that you can return the vertices in any order.
 *  
 *  Example 1:
 *  Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
 *  Output: [0,3]
 *  Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. 
 *  From 3 we can reach [3,4,2,5]. So we output [0,3].
 * 
 *  Example 2:
 *  Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
 *  Output: [0,2,3]
 *  Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. 
 *  Also any of these vertices can reach nodes 1 and 4.
 *  
 *  Constraints:
 *  2 <= n <= 10^5
 *  1 <= edges.length <= min(10^5, n * (n - 1) / 2)
 *  edges[i].length == 2
 *  0 <= fromi, toi < n
 *  All pairs (fromi, toi) are distinct. **/

/* 처음에 내가 생각한 방법. 빠를 줄 알았는데 생각보다 그렇게 빠르지는 않네 */

package leet_code.java_2021_1;
import java.util.List;
import java.util.ArrayList;

public class FindSmallestSetOfVertices {
    List<Integer>[] reverseGraph;

    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> answer = new ArrayList<>();
        reverseGraph = new ArrayList[n];

        for (int i = 0; i < n; ++i) {
            reverseGraph[i] = new ArrayList<>();
        }

        for (int i = 0; i < edges.size(); ++i) {
            int source = edges.get(i).get(0);
            int destination  = edges.get(i).get(1);
            reverseGraph[destination].add(source);
        }

        for (int i = 0; i < n; ++i) {
            if (reverseGraph[i].isEmpty()) {
                answer.add(i);
            }
        }

        return answer;
    }
}
