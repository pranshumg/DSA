#include <bits/stdc++.h>

using namespace std;

/* Insert kth */

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
Node* insert_kth(Node* head, int val, int k) {
    if (k <= 0) {
        return head;
    }
    if (!head) {
        return (k == 1 ? new Node(val) : head);
    }
    if (k == 1) {
        return new Node(val, head);
    }
    Node* cur = head;
    for (int i = 1; i < k - 1 && cur; i++) {
        cur = cur->next;
    }
    if (!cur) {
        return head;
    }
    cur->next = new Node(val, cur->next);
    return head;
}