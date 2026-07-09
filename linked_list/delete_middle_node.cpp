#include <bits/stdc++.h>

using namespace std;

/* Delete middle node */
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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

Node* delete_kth_node(Node* head, int k) {
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

// TC - O(n), SC - O(1)
Node* delete_middle(Node* head) {
    int len = 0;
    Node* cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return delete_kth_node(head, len / 2 + 1);
}

// TC - O(n), SC - O(1)
Node* delete_middle(Node* head) {
    if (!head) {
        return head;
    }
    if (!head->next) {
        delete head;
        return nullptr;
    }
    Node* slow = head;
    Node* fast = head->next->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* del = slow->next;
    slow->next = del->next;
    delete del;
    return head;
}