#include <bits/stdc++.h>

using namespace std;

/* Sort a Linked List of 0's 1's and 2's */

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

// TC - O(n), SC - O(1)
Node* sort_0_1_2(Node* head) {
  Node* cur = head;
  int zero = 0, one = 0, two = 0;
  while (cur) {
    if (cur->info == 0) {
      zero++;
    } else if (cur->info == 1) {
      one++;
    } else {
      two++;
    }
    cur = cur->next;
  }   
  cur = head;
  while (cur) {
    if (zero) {
      cur->info = 0;
      zero--;
    } else if (one) {
      cur->info = 1;
      one--;
    } else {
      cur->info = 2;
      two--;
    }
    cur = cur->next;
  }
  return head;
}

// TC - O(n), SC - O(1)
Node* sort_0_1_2(Node* head) {
  Node* zero = new Node(-1);
  Node* first_zero = zero;
  Node* one = new Node(-1);
  Node* first_one = one;
  Node* two = new Node(-1);
  Node* first_two = two;
  Node* cur = head;
  while (cur) {
    if (cur->info == 0) {
      zero->next = cur;
      zero = zero->next;
    } else if (cur->info == 1) {
      one->next = cur;
      one = one->next;
    } else {
      two->next = cur;
      two = two->next;
    }
    cur = cur->next;
  }
  zero->next = (first_one->next ? first_one->next : first_two->next);
  one->next = first_two->next;
  two->next = nullptr;
  Node* res = first_zero->next;
  delete first_zero;
  delete first_one;
  delete first_two;
  return res;
}