#include <bits/stdc++.h>

using namespace std;

/* Merge two sorted linked list */
// https://leetcode.com/problems/merge-two-sorted-lists/

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

// TC - O(n + m), SC - O(1)
Node* merge(Node* first, Node* second) {
    Node* head = new Node(-1);
    Node* cur = head;
    Node* cur_first = first;
    Node* cur_second = second;
    while (cur_first && cur_second) {
        if (cur_first->info <= cur_second->info) {
            cur->next = cur_first;
            cur_first = cur_first->next;
        } else {
            cur->next = cur_second;
            cur_second = cur_second->next;
        }
        cur = cur->next;
    }
    while (cur_first) {
        cur->next = cur_first;
        cur_first = cur_first->next;
        cur = cur->next;
    }
    while (cur_second) {
        cur->next = cur_second;
        cur_second = cur_second->next;
        cur = cur->next;
    }
    Node* del = head;
    head = head->next;
    delete del;
    return head;
}