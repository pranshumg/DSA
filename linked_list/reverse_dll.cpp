#include <bits/stdc++.h>

using namespace std;

/* Reverse a doubly linked list */

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

// TC - O(n), SC - O(n)
Node* reverse_dll(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    stack<int> sk;
    Node* cur = head;
    while (cur) {
        sk.push(cur->info);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        cur->info = sk.top();
        cur = cur->next;
        sk.pop();
    }
    return head;
}

// TC - O(n), SC - O(1)
Node* reverse_dll(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    Node* cur = head;
    Node* prev = nullptr;
    while (cur) {
        cur->prev = cur->next;
        cur->next = prev;
        prev = cur;
        cur = cur->prev;
    }   
    return prev;
}