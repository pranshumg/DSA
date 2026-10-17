#include <bits/stdc++.h>

using namespace std;

// Clone linked list with random pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Node {
public:
  int info;
  Node* next;
  Node* random;

  Node(int info) {
    this->info = info; 
    this->next = nullptr;
    this->random = nullptr;
  }

  Node(int info, Node* next, Node* random) {
    this->info = info;  
    this->next = next;
    this->random = random;
  }
};

// TC - O(n), SC - O(n)
Node* clone_ll(Node* head) {
  if (!head) {
    return head;
  }
  unordered_map<Node*, Node*> ump;
  Node* cur = head;
  while (cur) {
    ump[cur] = new Node(cur->info);
    cur = cur->next;
  }
  cur = head;
  while (cur) {
    ump[cur]->next = ump[cur->next];
    ump[cur]->random = ump[cur->random];
    cur = cur->next;
  }
  return ump[head];
}

// TC - O(n), SC - O(1)
Node* clone_ll(Node* head) {
  if (!head) {
    return head;
  }
  Node* cur = head;
  while (cur) {
    cur->next = new Node(cur->info, cur->next, nullptr);
    cur = cur->next->next;
  }
  cur = head;
  Node* new_head = head->next;
  while (cur) {
    if (cur->random) {
      cur->next->random = cur->random->next;
    }
    cur = cur->next->next;
  }
  cur = head;
  while (cur) {
    Node* tmp = cur->next->next;
    if (tmp) {
      cur->next->next = tmp->next;
    }
    cur->next = tmp;
    cur = cur->next;
  }
  return new_head;
}