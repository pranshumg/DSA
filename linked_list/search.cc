#include <bits/stdc++.h>

using namespace std;

/* Search in linked list */

class Node {
public:
  int info;
  Node* next;

  Node(int info) {
    this->info = info;
    this->next = nullptr;
  }
};

// TC - O(n), SC - O(1)
bool search(Node* head, int target) {
  for (Node* tmp = head; tmp; tmp = tmp->next) {
    if (tmp->info == target) {
      return true;
    }
  }
  return false;
}
