#include <bits/stdc++.h>

using namespace std;

/* Rotate a Linked List */
// https://leetcode.com/problems/rotate-list/

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
Node* rotate(Node* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }
    int len = 0;
    Node* cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    k %= len;
    if (k == 0) {
        return head;
    }
    cur = head;
    Node* slow = head;
    Node* fast = head;
    for (int i = 1; i <= k; i++) {
        fast = fast->next;
    }
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* new_head = slow->next;
    slow->next = nullptr;
    fast->next = head;
    return new_head;
}