#include "algorithm.h"
#include "graph.h"

int main(void) {
    Graph graph(9);
    graph.AddEdge(0,1);
    graph.AddEdge(1,2);
    graph.AddEdge(2,3);
    graph.AddEdge(1,4);
    graph.AddEdge(4,5);
    graph.AddEdge(5,6);
    graph.AddEdge(4,7);
    graph.AddEdge(1,8);

    std::vector<int> result = algorithm::DFS(graph);
    for (int i=0; i < result.size(); ++i) {
        std::cout << result[i] <<std::endl;
    }
}