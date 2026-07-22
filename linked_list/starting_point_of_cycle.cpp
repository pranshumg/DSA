#include <bits/stdc++.h>

using namespace std;

/* Starting point of cycle */
// https://leetcode.com/problems/linked-list-cycle-ii/

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

// TC - O(n log n), SC - O(n)
Node* starting_point(Node* head) {
  map<Node*, int> mp;
  Node* cur = head;
  while (cur) {
    if (mp.count(cur)) {
      return cur;
    }
    mp[cur]++;
    cur = cur->next;
  }
  return nullptr;
}

// TC - O(n), SC - O(1)
Node* starting_point(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}