#include <bits/stdc++.h>

using namespace std;

/* Array to linked list */

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
Node* arr_to_ll(vector<int>& v) {
    if (v.empty()) {
        return nullptr;
    }
    Node* head = new Node(v[0]);
    Node* tmp = head;
    for (int i = 1; i < int(v.size()); i++) {
        tmp->next = new Node(v[i]);
        tmp = tmp->next;
    }
    return head;
}