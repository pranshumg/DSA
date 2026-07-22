#include <bits/stdc++.h>

using namespace std;

/* Odd even linked list */
// https://leetcode.com/problems/odd-even-linked-list/

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

// TC - O(n), SC - O(n)
Node* odd_even(Node* head) {
  if (!head) {
    return head;
  }
  vector<int> v;
  Node* cur = head;
  while (cur && cur->next) {
    v.push_back(cur->info);
    cur = cur->next->next;
  }
  if (cur) {
    v.push_back(cur->info);
  }
  cur = head->next;
  while (cur && cur->next) {
    v.push_back(cur->info);
    cur = cur->next->next;
  }
  if (cur) {
    v.push_back(cur->info);
  }
  cur = head;
  for (int i = 0; i < int(v.size()); i++) {
    cur->info = v[i];
    cur = cur->next;
  }
  return head;
}

// TC - O(n), SC - O(1)
Node* odd_even(Node* head) {
  if (!head || !head->next || !head->next->next) {
    return head;
  }
  Node* odd = head;
  Node* even = head->next;
  while (even && even->next) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = head->next;
  return head;
}