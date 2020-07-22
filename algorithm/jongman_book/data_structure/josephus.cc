#include <iostream>

using namespace std;

int number_of_test_case;
int number_of_people;
int turn_count;
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
    return new_node;
}

Node *removeList(Node *prev, Node *cur) {
    // prev는 cur의 바로 이전 노드. cur 노드를 현재 list에서 제외함.
    prev->next = cur->next;
    cur->next = nullptr;
    free(cur);
    return prev->next;
}

void FindAliveNumber(Node *head) {
    int survive_people = number_of_people;
    Node *cur = head;
    Node *prev = head;
    for (int i=0; i < number_of_people-1; ++i) {
        prev = prev->next;
    }
    
    while (survive_people > 2) {
        removeList (prev, cur);
        for (int i=0; i < turn_count-1; ++i) {
            prev = prev->next;
        }
        cur = prev->next;
        survive_people--;
    }

    first_alive_number =  cur->number > prev->number ? prev->number : cur->number;
    second_alive_number =  cur->number > prev->number ? cur->number : prev->number;

    free (prev);
    free (cur);
}

int main() {
    cin >> number_of_test_case;

    for (int i=0; i < number_of_test_case; ++i) {
        cin >> number_of_people >> turn_count;
        
        Node *head = (Node *)malloc(sizeof(Node));
        head->next = head;
        head->number = 1;
        Node *node = head;
        
        for (int j=2; j <= number_of_people; ++j) {
            node = addTail(j, node);
        }

        FindAliveNumber(head);
        cout << first_alive_number << " " << second_alive_number << endl;
    }

    return 0;
}


