#include "graph.h"

Graph::Graph(int count_of_vertex) {
    for (int i=0; i < count_of_vertex; ++i) {
        LinkedList *adj_list = new LinkedList();
        adjacency_list_.push_back(adj_list);
    }
}
Graph::~Graph() {
    for (LinkedList *iter : adjacency_list_) {
        free(iter);
    }
}

void Graph::AddEdge(int start, int end) {
    int count_of_vertex = adjacency_list_.size();
    if (start < 0 || end < 0 || start > count_of_vertex || end > count_of_vertex) { 
        std::cout << "vertex does not exists" << std::endl;
        return;
    }

    LinkedList *start_list = adjacency_list_[start];
    LinkedList *end_list = adjacency_list_[end];
    Node *end_node = new Node(end);
    Node *start_node = new Node(start);
    start_list->insert(end_node);
    end_list->insert(start_node);
}

void Graph::PrintNeighbor(int vertex) {
    if (vertex < 0 || vertex > adjacency_list_.size()) {
        std::cout << "vertex does not exits" << std::endl;
        return;
    }
    LinkedList *adj_list = adjacency_list_[vertex];
    adj_list->printList();
}

std::vector<LinkedList *> &Graph::AdjacencyList() {
    return adjacency_list_;
}

int Graph::CountOfVertices() { return adjacency_list_.size();}