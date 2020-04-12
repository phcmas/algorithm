#include <vector>
#include "graph.h"
#include "stack.h"

namespace algorithm {
    std::vector<int> DFS (Graph &graph) {
        int count = graph.CountOfVertices();
        if (count == 0) {
            std::cout << "There is no vertices" << std::endl;
            return;
        }

        std::vector<LinekdList *> adjacency_list = graph.AdjacencyList();
        std::vector<bool> is_visited (count, false);
        std::vector<int> result;
        Stack visited_nodes;
        visited_nodes.insert(0);
        result.push_back(0);
        is_visited[0] = true;
        LinkedList *current_list = adjacency_list[0];
        while (!visited_nodes.empty()) {
            while (true) {
                Node *current = current_list->head();
                int current_data = current->data();
                if (is_visited[current_data]) {
                    if (current->next() == nullptr) {
                        visited_nodes.pop();
                        current_list = adjacency_list[visited_nodes.top()];
                        break;
                    }
                } else {
                    visited_nodes.insert(current_data);
                    is_visited[current_data] = true;
                    result.push_back(current_data);
                    current_list = adjacency_list[current_data];
                    break;
                }
            }
        }
        return result;
    }

}