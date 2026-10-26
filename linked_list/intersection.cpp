#include <bits/stdc++.h>

using namespace std;

/* Intersection point of a Y linked list */
// https://leetcode.com/problems/intersection-of-two-linked-lists/

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

// TC - O((n + m) log n), SC - O(n)
Node* intersection(Node* first, Node* second) {
    map<Node*, int> mp;
    Node* cur = first;
    while (cur) {
        mp[cur]++;
        cur = cur->next;
    }
    cur = second;
    while (cur) {
        if (mp.count(cur)) {
            return cur;
        }
        cur = cur->next;
    }
    return cur;
}

// TC - O(n + m), SC - O(1)
Node* intersection(Node* first, Node* second) {
    int len_first = 0;
    Node* tmp_first = first;
    while (tmp_first) {
        len_first++;
        tmp_first = tmp_first->next;
    }
    int len_second = 0;
    Node* tmp_second = second;
    while (tmp_second) {
        len_second++;
        tmp_second = tmp_second->next;
    }
    tmp_first = first;
    tmp_second = second;
    int dif = abs(len_first - len_second);
    for (int i = 0; i < dif; i++) {
        len_first > len_second ? tmp_first = tmp_first->next : tmp_second = tmp_second->next;
    }
    while (tmp_first) {
        if (tmp_first == tmp_second) {
            return tmp_first;
        }
        tmp_first = tmp_first->next;
        tmp_second = tmp_second->next;
    }
    return tmp_first;
}