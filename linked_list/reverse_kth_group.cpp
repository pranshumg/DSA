#include <bits/stdc++.h>

using namespace std;

/* Reverse Nodes in k-Group */
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

Node* reverse(Node* head) {
    Node* cur = head;
    Node* prev = nullptr;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

// TC - O(n), SC - O(1)
Node* reverse_k_group(Node* head, int k) {
    if (!head || k == 1) {
        return head;
    }
    Node* cur = head;
    Node* prev_last = nullptr;
    Node* new_head = head;
    while (cur) {
        Node* kth = cur;
        for (int i = 1; i < k && kth; i++) {
            kth = kth->next;
        }
        if (!kth) {
            break;
        }
        Node* nxt_grp = kth->next;
        kth->next = nullptr;
        Node* rev_head = reverse(cur);
        if (cur == head) {
            new_head = rev_head;
        } else {
            prev_last->next = rev_head;
        }
        prev_last = cur;
        cur->next = nxt_grp;
        cur = nxt_grp;
    }
    return new_head;
}