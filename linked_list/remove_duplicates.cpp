#include <bits/stdc++.h>

using namespace std;

/* Remove duplicates in doubly linked list */

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

    Node(int info, Node* prev, Node* next) {
        this->info = info;  
        this->prev = prev;
        this->next = next;
    }
};

// TC - O(n), SC - O(1)
Node* remove_duplicates(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    Node* cur = head->next;
    while (cur) {
        Node* nxt = cur->next;
        if (cur->info == cur->prev->info) {
            cur->prev->next = cur->next;
            if (cur->next) {
                cur->next->prev = cur->prev;
            }
            delete cur;
        }
        cur = nxt;
    }
    return head;
}