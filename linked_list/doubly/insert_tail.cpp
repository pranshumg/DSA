#include <bits/stdc++.h>

using namespace std;

/* Insert tail */

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

    Node(int info, Node* prev) {
        this->info = info;
        this->prev = prev;  
        this->next = nullptr;
    }
};

// TC - O(n), SC - O(1)
Node* insert_tail(Node* head, int val) {
    if (!head) {
        return new Node(val);
    }
    Node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new Node(val, cur);
    return head;
}