#include <bits/stdc++.h>

using namespace std;

/* Insert head */

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

    Node(int info, Node* next) {
        this->info = info;
        this->prev = nullptr;  
        this->next = next;
    }
};

// TC - O(1), SC - O(1)
Node* insert_head(Node* head, int val) {
    if (!head) {
        return new Node(val);
    }
    Node* node = new Node(val, head);
    head->prev = node;
    return node;
}