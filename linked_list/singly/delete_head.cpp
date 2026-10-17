#include <bits/stdc++.h>

using namespace std;

/* Delete head */

class Node {
public:
  int info;
  Node* next;

  Node(int info) {
    this->info = info;
    this->next = nullptr;
  }
};

// TC - O(1), SC - O(1)
Node* delete_head(Node* head) {
  if (!head) {
    return nullptr;
  }
  Node* tmp = head;
  head = head->next;
  delete tmp;
  return head;
}