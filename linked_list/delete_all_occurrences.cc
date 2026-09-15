#include <bits/stdc++.h>

using namespace std;

/* Delete all occurrences of a key in doubly linked list */

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
Node* delete_all_occurrences(Node* head, int key) {
  if (!head) {
    return head;
  }
  Node* cur = head;
  while (cur) {
    Node* nxt = cur->next;
    if (cur->info == key) {
      if (cur->prev) {
        cur->prev->next = cur->next;
      } else {
        head = cur->next;
      }
      if (cur->next) {
        cur->next->prev = cur->prev;
      }
      delete cur;
    }
    cur = nxt;
  }
  return head;
}