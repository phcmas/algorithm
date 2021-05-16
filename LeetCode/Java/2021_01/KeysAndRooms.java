/* 841. Keys and Rooms */
/** There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, 
 *  and each room may have some keys to access the next room. 
 *  Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] 
 *  where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
 *  Initially, all the rooms start locked (except for room 0). 
 *  You can walk back and forth between rooms freely.
 *  Return true if and only if you can enter every room.
 * 
 *  Example 1:
 *  Input: [[1],[2],[3],[]]
 *  Output: true
 *  Explanation:  
 *  We start in room 0, and pick up key 1.
 *  We then go to room 1, and pick up key 2.
 *  We then go to room 2, and pick up key 3.
 *  We then go to room 3.  Since we were able to go to every room, we return true.
 * 
 *  Example 2:
 *  Input: [[1,3],[3,0,1],[2],[0]]
 *  Output: false
 *  Explanation: We can't enter the room with number 2.
 * 
 *  Note:
 *  1 <= rooms.length <= 1000
 *  0 <= rooms[i].length <= 1000
 *  The number of keys in all rooms combined is at most 3000 **/

 /* dfs, bfs 연습하려고 쉬어갈겸 풀었던 문제 */

import java.util.ArrayDeque;
import java.util.List;
import java.util.Queue;
import java.util.HashSet;

public class KeysAndRooms {
    private void dfs(List<List<Integer>> rooms, boolean[] visited, int num) {
        List<Integer> adj = rooms.get(num);
        visited[num] = true;

        for (int next : adj) {
            if (visited[next]) continue;
            dfs (rooms, visited, next);
        }
    }

    public boolean canVisitAllRooms2(List<List<Integer>> rooms) {
        // bfs 이용
        HashSet<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(0);

        while (!queue.isEmpty()) {
            int cur = queue.poll();
            List<Integer> adj = rooms.get(cur);
            visited.add(cur);

            for (int next : adj) {
                if (visited.contains(next)) continue;
                queue.add(next);
            }
        }

        return visited.size() == rooms.size();
    }

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        // dfs 이용
        boolean[] visited = new boolean[rooms.size()];
        dfs(rooms, visited, 0);

        for (int i = 0; i < visited.length; ++i) {
            if (visited[i] == false) return false;
        }

        return true;
    }
}



