#include "sort_algorithm.h"
#include "graph.h"

int main(void) {
    Graph graph(8);
    graph.AddEdge(1,2);
    graph.AddEdge(1,3);
    graph.AddEdge(1,6);
    graph.AddEdge(2,7);
    graph.AddEdge(6,7);
    graph.AddEdge(3,4);
    graph.AddEdge(4,5);
    graph.PrintNeighbor(1);
    graph.PrintNeighbor(2);

}