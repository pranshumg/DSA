#include <bits/stdc++.h>

using namespace std;

/* Insert node before target */

class Node {
public:
    int info;
    Node* next;

    Node(int info) {
        this->info = info;  
        this->next = nullptr;
    }

    Node(int info, Node* next) {
        this->info = info;
        this->next = next;
    }
};

// TC - O(n), SC - O(1)
Node* insert_node(Node* head, int val, int target) {
    if (!head) {
        return head;
    }
    if (head->info == target) {
        return new Node(val, head);
    }
    Node* cur = head;
    while (cur->next && cur->next->info != target) {
        cur = cur->next;
    }
    if (!cur->next) {
        return head;
    }
    cur->next = new Node(val, cur->next);
    return head;
}