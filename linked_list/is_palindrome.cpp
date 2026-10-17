#include <bits/stdc++.h>

using namespace std;

/* Palindrome linked list */
// https://leetcode.com/problems/palindrome-linked-list/

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
bool is_palindrome(Node* head) {
  stack<int> sk;
  Node* cur = head;
  while (cur) {
    sk.push(cur->info);
    cur = cur->next;
  }
  cur = head;
  while (cur) {
    if (cur->info != sk.top()) {
      return false;
    }
    cur = cur->next;
    sk.pop();
  }
  return true;
}

// TC - O(n), SC - O(1)
bool is_palindrome(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
  }
  auto reverse = [](Node* head) -> Node* {
    Node* cur = head;
    Node* prev = nullptr;
    while (cur) {
      Node* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  };
  Node* left = head;
  Node* right = (!fast ? reverse(slow) : reverse(slow->next));
  while (right) {
    if (left->info != right->info) {
      return false;
    }
    left = left->next;
    right = right->next;
  }
  return true;
}