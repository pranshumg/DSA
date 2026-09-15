#include <bits/stdc++.h>

using namespace std;

/* Pairs with given sum in doubly linked list */

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

// TC - O(n log n), SC - O(n)
vector<pair<int, int>> pairs(Node* head, int target) {
  vector<pair<int, int>> ans;
  map<int, int> mp;
  Node* cur = head;
  while (cur) {
    if (mp.count(target - cur->info)) {
      ans.emplace_back(target - cur->info, cur->info);
    }
    mp[cur->info]++;
    cur = cur->next;
  }
  return ans;
}

// TC - O(n), SC - O(1)
vector<pair<int, int>> pairs(Node* head, int target) {
  vector<pair<int, int>> ans;
  if (!head) {
    return ans;
  }
  Node* first = head;
  Node* last = head;
  while (last->next) {
    last = last->next;
  }
  while (first != last && first->prev != last) {
    int sum = first->info + last->info;
    if (sum == target) {
      ans.emplace_back(first->info, last->info);
      first = first->next;
      last = last->prev;
    } else if (sum < target) {
      first = first->next;
    } else {
      last = last->prev;
    }
  }
  return ans;
}