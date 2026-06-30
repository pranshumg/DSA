#include <bits/stdc++.h>

using namespace std;

/* Insert head */

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

// TC - O(1), SC - O(1)
Node* insert_head(Node* head, int val) {
    return new Node(val, head);
}