#include <bits/stdc++.h>

using namespace std;

/* Delete node */

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
Node* delete_node(Node* head, int k) {
    if (!head || k <= 0) {
        return head;
    }
    if (k == 1) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return head;    
    }
    Node* cur = head;
    for (int i = 1; i < k - 1 && cur; i++) {
        cur = cur->next;
    }
    if (!cur || !cur->next) {
        return head;
    }
    Node* del = cur->next;
    cur->next = del->next;
    delete del;
    return head;
}