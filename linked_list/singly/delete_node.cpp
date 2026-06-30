#include <bits/stdc++.h>

using namespace std;

/* Delete node by value */

class Node {
public:
    int info;
    Node* next;

    Node(int info) {
        this->info = info;
        this->next = nullptr;
    }
};

// TC - O(n), SC - O(1)
Node* delete_node(Node* head, int target) {
    if (!head) {
        return head;
    }
    if (head->info == target) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return head;    
    }
    Node* cur = head;
    while (cur->next && cur->next->info != target) {
        cur = cur->next;
    }
    if (!cur->next) {
        return head;
    }
    Node* del = cur->next;
    cur->next = del->next;
    delete del;
    return head;
}