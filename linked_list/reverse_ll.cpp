#include <bits/stdc++.h>

using namespace std;

// Reverse a singly linked list
// https://leetcode.com/problems/reverse-linked-list/

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

// Iterative
// TC - O(n), SC - O(1)
Node* reverse_ll(Node* head) {
  Node* cur = head;
  Node* prev = nullptr;
  while (cur) {
    Node* next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next; 
  }
  return prev;
}

// Recursive
// TC - O(n), SC - O(n)
Node* reverse_ll_rec(Node* head) {
  auto solve = [](auto&& self, Node* cur, Node* prev) -> Node* {
    if (!cur) {
      return prev;
    }
    Node* next = cur->next;
    cur->next = prev;
    return self(self, next, cur);
  };
  return solve(solve, head, nullptr);
 }