#include <bits/stdc++.h>

using namespace std;

/* Insert node before target */

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
Node* insert_node(Node* head, int val, int target) {
  if (!head) {
    return head;
  }
  if (head->info == target) {
    Node* node = new Node(val, nullptr, head);
    head->prev = node;
    return node;
  }
  Node* cur = head;
  while (cur->next && cur->next->info != target) {
    cur = cur->next;
  }
  if (!cur->next) {
    return head;
  }
  Node* node = new Node(val, cur, cur->next);
  cur->next->prev = node;
  cur->next = node;
  return head;
}