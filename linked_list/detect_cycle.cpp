#include <bits/stdc++.h>

using namespace std;

/* Detect cycle in linked list */
// https://leetcode.com/problems/linked-list-cycle/

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
bool detect_cycle(Node* head) {
  map<Node*, int> mp;
  Node* cur = head;
  while (cur) {
    if (mp.count(cur)) {
      return true;
    }
    mp[cur]++;
    cur = cur->next;
  }
  return false;
}

// TC - O(n), SC - O(1)
bool detect_cycle(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      return true;
    }
  }
  return false;
}