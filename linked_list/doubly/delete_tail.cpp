#include <bits/stdc++.h>

using namespace std;

/* Delete tail */

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
};

// TC - O(n), SC - O(1)
Node* delete_tail(Node* head) {
  if (!head) {
    return head;
  }
  if (!head->next) {
    delete head;
    return nullptr;
  }
  Node* tmp = head;
  while (tmp->next->next) {
    tmp = tmp->next;
  }
  delete tmp->next;
  tmp->next = nullptr;
  return head;
}