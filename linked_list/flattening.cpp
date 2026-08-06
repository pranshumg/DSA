#include <bits/stdc++.h>

using namespace std;

/* Flattening a linked list */

class Node {
public:
  int info;
  Node* next;
  Node* child;

  Node(int info) {
    this->info = info; 
    this->next = nullptr;
    this->child = nullptr;
  }

  Node(int info, Node* next, Node* child) {
    this->info = info;  
    this->next = next;
    this->child = child;
  }
};

// TC - O(n log n), SC - O(n)
// where n is the total number of nodes
Node* flatten(Node* head) {
  vector<int> v;
  Node* cur = head;
  while (cur) {
    Node* tmp = cur;
    while (tmp) {
      v.push_back(tmp->info);
      tmp = tmp->child;
    }
    cur = cur->next;
  }
  if (v.empty()) {
    return nullptr;
  }
  sort(v.begin(), v.end());
  Node* new_head = new Node(v.front());
  cur = new_head;
  for (int i = 1; i < int(v.size()); i++) {
    cur->child = new Node(v[i]);
    cur = cur->child;
  }
  return new_head;
}

// TC - O(n1 + n2), SC - O(1)
// where n1 and n2 are the sizes of the two child lists
Node* merge(Node* first, Node* second) {
  Node* tmp1 = first;
  Node* tmp2 = second;
  Node dummy(-1);
  Node* cur = &dummy;
  while (tmp1 && tmp2) {
    if (tmp1->info <= tmp2->info) {
      cur->child = tmp1;
      tmp1 = tmp1->child;
    } else {
      cur->child = tmp2;
      tmp2 = tmp2->child;
    }
    cur = cur->child;
    cur->next = nullptr;
  }
  cur->child = tmp1 ? tmp1 : tmp2;
  while (cur->child) {
    cur = cur->child;
    cur->next = nullptr;
  }
  return dummy.child;
}

// TC - O(n * k), SC - O(k)
// where n is the total number of nodes and
// k is the number of linked lists connected by next pointers
Node* flatten(Node* head) {
  if (!head || !head->next) {
    return head;
  }
  head->next = flatten(head->next);
  return merge(head, head->next);
}