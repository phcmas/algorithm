#include "linked_list.h"
#include <vector>

class Graph {
public:
Graph(int count_of_vertex);
~Graph();
void AddEdge(int start, int end);
void PrintNeighbor(int vertex);
std::vector<LinkedList *> &AdjacencyList();
int CountOfVertices();

 
private:
std::vector<LinkedList *> adjacency_list_;
};