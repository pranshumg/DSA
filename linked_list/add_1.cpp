#include <bits/stdc++.h>

using namespace std;

/* Add 1 to a number represented by linked list */

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

// TC - O(n), SC - O(1)
Node* add_1(Node* head) {
  if (!head) {
    return new Node(1);
  }
  head = reverse_ll(head);
  Node* cur = head;
  Node* prev = nullptr;
  int carry = 1;
  while (cur && carry) {
    int sum = cur->info + carry;
    cur->info = sum % 10;
    carry = sum / 10;
    prev = cur;
    cur = cur->next;
  }
  if (carry) {
    prev->next = new Node(carry);
  }
  return reverse_ll(head);
}

// TC - O(n), SC - O(n)
Node* add_1(Node* head) {
  auto solve = [&](auto&& self, Node* cur, int& carry) -> void {
    if (!cur) {
      return;
    }
    self(self, cur->next, carry);
    int sum = cur->info + carry;
    cur->info = sum % 10;
    carry = sum / 10;
  };
  int carry = 1;
  solve(solve, head, carry);
  if (carry) {
    return new Node(carry, head);
  }
  return head;
}