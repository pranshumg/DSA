#include <bits/stdc++.h>

using namespace std;

/* Insert before kth node */

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

// TC - O(n), SC - O(1)
Node* insert_kth(Node* head, int val, int k) {
  if (!head || k <= 0) {
    if (k == 1) {
      return new Node(val);
    }
    return head;
  }
  if (k == 1) {
    Node* node = new Node(val, nullptr, head);
    head->prev = node;
    return node;
  }
  Node* cur = head;
  for (int i = 1; i < k - 1 && cur; i++) {
    cur = cur->next;
  }
  if (!cur) {
    return head;
  }
  if (!cur->next) {
    cur->next = new Node(val, cur, nullptr);
    return head;
  }
  Node* node = new Node(val, cur, cur->next);
  cur->next->prev = node;
  cur->next = node;
  return head;
}