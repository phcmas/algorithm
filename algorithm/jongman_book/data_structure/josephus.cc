#include <iostream>

using namespace std;

int number_of_test_case;
int number_of_people;
int order;
int first_alive_number;
int second_alive_number;

struct Node {
    int number;
    Node *next;
};

Node *addTail(int number, Node *node) {
    //항상 node는 linked list의 마지막 노드가 들어와야함
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->number = number;
    new_node->next = node->next;
    node->next = new_node;
}

void removeList(int number, Node *node) {

}

void FindAliveNumber(Node *head) {

}

int main() {
    cin >> number_of_test_case;

    for (int i=0; i < number_of_test_case; ++i) {
        cin >> number_of_people >> order;
        
        Node *head = (Node *)malloc(sizeof(Node));
        head->next = head;
        Node *node = head;
        
        for (int j=1; j <= number_of_people; ++j) {
            node = addTail(j, node);
        }

        FindAliveNumber(head);
        cout << first_alive_number << second_alive_number << endl;
    }
    

    return 0;
}