#include <bits/stdc++.h>

using namespace std;

/* Traverse */

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
void traverse(Node* head) {
    for (Node* tmp = head; tmp; tmp = tmp->next) {
        cout << tmp->info << " \n"[tmp->next == nullptr];
    }
}