#include <bits/stdc++.h>

using namespace std;

/* Insert tail */

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
Node* insert_tail(Node* head, int val) {
  if (!head) {
    return new Node(val);
  }
  Node* cur = head;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = new Node(val);
  return head;
}