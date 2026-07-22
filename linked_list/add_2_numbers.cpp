#include <bits/stdc++.h>

using namespace std;

/* Add two numbers in Linked list */
// https://leetcode.com/problems/add-two-numbers/

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

  Node(int info, Node* prev, Node* next) {
    this->info = info;
    this->prev = prev;  
    this->next = next;
  }
};

// TC - O(max(n, m)), SC - O(max(n, m))
Node* add(Node* first, Node* second) {
  Node* node = new Node(0);
  Node* tmp = node;
  int carry = 0;
  while (first || second) {
    int sum = carry;
    if (first) {
      sum += first->info;
    }
    if (second) {
      sum += second->info; 
    }
    node->info = sum % 10;
    carry = sum / 10;
    node->next = new Node(0, node, nullptr);
    node = node->next;
    if (first) {
      first = first->next;
    }
    if (second) {
      second = second->next;
    }
  }
  if (carry) {
    node->info = 1;
  } else {
    if (node->prev) {
      node->prev->next = nullptr;
      delete node;
    } else {
      delete node;
      return nullptr;
    }
  }
  return tmp;
}