#ifndef _ALGORITHM_
#define _ALGORITHM_

#include <vector>
#include <utility>
#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"

namespace algorithm {
    /* DFS, BFS */
    std::vector<int> DFS (Graph &graph) {
        /* 리팩토링 필요 */
        int count = graph.CountOfVertices();
        if (count == 0) {
            std::cout << "There is no vertices" << std::endl;
            return std::vector<int> ();
        }

        std::vector<LinkedList *> adjacency_list = graph.AdjacencyList();
        std::vector<bool> is_visited (count, false);
        std::vector<int> result;
        Stack visited_nodes(0);
        result.push_back(0);
        is_visited[0] = true;
        LinkedList *current_list = adjacency_list[0];

        while (!visited_nodes.empty()) {
            Node *current = current_list->head();
            while (true) {
                int current_data = current->data();
                if (is_visited[current_data]) {
                    if (current->next() == nullptr) {
                        visited_nodes.pop();
                        if (!visited_nodes.empty()){current_list = adjacency_list[visited_nodes.top()];}
                        break;
                    } else {
                        current = current->next();
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

    std::vector<int> BFS (Graph &graph) {
        int count = graph.CountOfVertices();
        if (count == 0) {
            std::cout << "There is no vertices" << std::endl;
            return std::vector<int> ();
        }

        std::vector<LinkedList *> adjacency_list = graph.AdjacencyList();
        std::vector<bool> is_visited (count, false);
        std::vector<int> result;
        Queue queue(0);
        is_visited[0] = true;

        while (!queue.empty()) {
            int data = queue.pop();
            result.push_back(data);
            LinkedList *current_list = adjacency_list[data];
            Node *current = current_list->head();
            while (current !=nullptr) {
                if (!is_visited[current->data()]) {
                    queue.insert (current->data());
                    is_visited[current->data()] = true;
                }
                current = current->next();
            }
        }
        return result;
    }

    /* Binary Serach */
    void InsertBinarySearchTree(BinaryTree *node, int data) {
        BinaryTree *new_node = new BinaryTree(data);
        
        if (data <= node->data()) {
            BinaryTree *left = node->left();
            if (left == nullptr) { 
                node->set_left(new_node);
                return;
            }
            InsertBinarySearchTree(left, data);
        } else {
            BinaryTree *right = node->right();
            if (right == nullptr) { 
                node->set_right(new_node);
                return;
            }
            InsertBinarySearchTree(right, data);
        }
    }

    BinaryTree *BinarySearch(BinaryTree *node, int data) {
        if (node == nullptr) return nullptr;
        if (node->data() == data) return node;
        else if (node->data() < data) return BinarySearch(node->left(), data);
        else return BinarySearch(node->right(),data);
    }

    void Swap (BinaryTree *node1, BinaryTree *node2) {
        int temp = node1->data();
        node1->set_data(node2->data());
        node2->set_data(temp);
    }

    BinaryTree *FindMinParent (BinaryTree *root) {
        BinaryTree *node = root->right();
        if (!node->has_left()) return root;

        while (true) {
            if (!node->left()->has_left()) break;
            else {
                node = node->left();
            }
        }
        return node;
    }

    BinaryTree *FindNode (BinaryTree *root, int data) {
        if (root == nullptr) { return nullptr; }
        else if (data == root->data()) {
            return root;
        } else if (data < root->data()) {
            FindNode(root->left(),data);
        } else {
            FindNode(root->right(), data);
        }
    }

    void RemoveNode(BinaryTree *root, BinaryTree *node) {
        if (!root->has_children()) { free(root);}
        if (root->left() == node) {
            free(node->left());
            root->set_left(nullptr);
            return;
        } else if (root->right() == node) {
            free(node->right());
            root->set_right(nullptr);
            return;
        }

        if (node->data() < root->data()) {
            RemoveNode(node->left(), node);
        } else if (node->data() > root->data()) {
            RemoveNode(node->right(), node);
        } 
    }

    void DeleteBinarySearchTree(BinaryTree *&root, int data) {
        BinaryTree *node = FindNode(root, data);
        
        if (!node->has_children()) {
            RemoveNode(root, node);
        } else if (node->has_left() && !node->has_right()) {
            BinaryTree *left = node->left();
            Swap (node, left);
            node->set_left(left->left());
            node->set_right(left->right());
            free(left);
        } else if (node->has_right() && !node->has_left()) {
            BinaryTree *right = node->right();
            Swap (node, right);
            node->set_left(right->left());
            node->set_right(right->right());
            free(right);
        } else {
            if (node->right()->has_left()) {
                BinaryTree *next_min_parent = FindMinParent(node);
                BinaryTree *next_min = next_min_parent->left();
                Swap (node, next_min);
                next_min_parent->set_left(nullptr);
                free(next_min);
            } else {
                BinaryTree *right = node->right();
                Swap(node, right);
                node->set_right(right->right());
                free(right);
            }
        }
    }

    void PrintPreOrder(BinaryTree *root) {
        if (root == nullptr) return;
        std::cout<< root->data() << " ";
        PrintPreOrder(root->left());
        PrintPreOrder(root->right());
    }





}


#endif