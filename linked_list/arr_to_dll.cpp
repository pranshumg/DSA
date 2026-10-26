#include <bits/stdc++.h>

using namespace std;

/* Array to doubly linked list */

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

// TC - O(n), SC - O(n)
Node* arr_to_dll(vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }
    Node* head = new Node(v[0]);
    Node* tmp = head;
    for (int i = 1; i < int(v.size()); i++) {
        tmp->next = new Node(v[i]);
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    return head;
}