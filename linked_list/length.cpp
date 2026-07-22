#include <bits/stdc++.h>

using namespace std;

/* Length of linked list */

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
int length(Node* head) {
  int cnt = 0;
  for (Node* tmp = head; tmp; tmp = tmp->next) {
    cnt++;
  }
  return cnt;
} 