#include <bits/stdc++.h>

using namespace std;

/* Delete head */

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

// TC - O(1), SC - O(1)
Node* delete_head(Node* head) {
  if (!head) {
    return head;
  }
  if (!head->next) {
    delete head;
    return nullptr;
  }
  Node* tmp = head;
  head = head->next;
  head->prev = nullptr;
  delete tmp;
  return head;
}