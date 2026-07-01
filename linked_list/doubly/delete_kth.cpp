#include <bits/stdc++.h>

using namespace std;

/* Delete kth node */

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
Node* delete_kth(Node* head, int k) {
    if (!head || k <= 0) {
        return head;
    }
    if (k == 1) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        if (head) { 
            head->prev = nullptr;
        }
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
    if (del->next) {
        del->next->prev = cur;
    }
    delete del;
    return head;
}