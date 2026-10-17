#include <bits/stdc++.h>

using namespace std;

/* Middle of a linked list */
// https://leetcode.com/problems/middle-of-the-linked-list/

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
Node* middle(Node* head) {
  int n = 0;
  Node* cur = head;
  while (cur) {
    n++;
    cur = cur->next;
  }
  int mid = n / 2;
  cur = head;
  while (mid--) {
    cur = cur->next;
  }
  return cur;
}

// TC - O(n), SC - O(1)
Node* middle(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}