#include <bits/stdc++.h>

using namespace std;

/* Delete node by val */

class Node {
public:
    int info;
    Node* prev;
    Node* next;

    Node(int info) {
        this->info = info;
        this->prev = nullptr;  
        this->next = nullptr;
    }
};

// TC - O(n), SC - O(1)
Node* delete_node(Node* head, int val) {
    if (!head) {
        return head;
    }
    if (head->info == val) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        if (head) {
            head->prev = nullptr;
        }
        return head;
    }
    Node* cur = head;
    while (cur->next && cur->next->info != val) {
        cur = cur->next;
    }
    if (!cur->next) {
        return head;
    }
    Node* del = cur->next;
    cur->next = del->next;
    if (del->next) {
        del->next->prev = cur;
    }
    delete del;
    return head;
}