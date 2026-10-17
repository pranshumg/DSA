#include <bits/stdc++.h>

using namespace std;

/* Remove nth node from the end */
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
Node* remove_nth_node(Node* head, int n) {
  int len = 0;
  Node* cur = head;
  while (cur) {
    len++;
    cur = cur->next;
  }
  return delete_kth_node(head, len - n + 1);
}

// TC - O(n), SC - O(1)
Node* remove_nth_node(Node* head, int n) {
  Node* fast = head;
  for (int i = 1; i <= n; i++) {
    fast = fast->next;
  }
  if (!fast) {
    Node* del = head;
    head = head->next;
    delete del;
    return head;
  }
  Node* slow = head;
  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
  }
  Node* del = slow->next;
  slow->next = del->next;
  delete del;
  return head;
};