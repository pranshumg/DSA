#include <bits/stdc++.h>

using namespace std;

/* Merge k sorted lists */
// https://leetcode.com/problems/merge-k-sorted-lists/

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

// TC - o(N log N), SC - O(N)
// where N is the total number of nodes across all linked lists
Node* merge_k_sorted_lists(vector<Node*>& v) {
  if (v.empty()) {
    return nullptr;
  }
  if (int(v.size()) == 1) {
    return v.front();
  }
  vector<int> res;
  for (int i = 0; i < int(v.size()); i++) {
    Node* cur = v[i];
    while (cur) {
      res.push_back(cur->info);
      cur = cur->next;
    }
  }
  if (res.empty()) {
    return nullptr;
  }
  sort(res.begin(), res.end());
  Node* head = new Node(res[0]);
  Node* cur = head;
  for (int i = 1; i < int(res.size()); i++) {
    cur->next = new Node(res[i]);
    cur = cur->next;
  }
  return head;  
}

// TC - O(n1 + n2), SC - O(1)
// where n1 and n2 are the sizes of the two linked lists
Node* merge(Node* first, Node* second) {
  Node* tmp1 = first;
  Node* tmp2 = second;
  Node dummy(-1);
  Node* cur = &dummy;
  while (tmp1 && tmp2) {
    if (tmp1->info <= tmp2->info) {
      cur->next = tmp1;
      tmp1 = tmp1->next;
    } else {
      cur->next = tmp2;
      tmp2 = tmp2->next;
    }
    cur = cur->next;
  }
  cur->next = tmp1 ? tmp1 : tmp2;
  return dummy.next;
}

// TC - O(N * K), SC - O(K)
// where N is the total number of nodes across all linked lists
// and K is the number of linked lists
Node* solve(int idx, vector<Node*>& v) {
  if (idx == int(v.size()) - 1) {
    return v[idx];
  }
  v[idx + 1] = solve(idx + 1, v);
  return merge(v[idx], v[idx + 1]);
}

Node* merge_k_sorted_lists(vector<Node*>& v) {
  if (v.empty()) {
    return nullptr;
  }
  if (int(v.size()) == 1) {
    return v.front();
  }
  return solve(0, v);
}

// TC - O(N log K), SC - O(K)
// where N is the total number of nodes in all lists
// and K is the number of linked lists
Node* merge_k_sorted_lists(vector<Node*>& v) {
  priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
  for (int i = 0; i < int(v.size()); i++) {
    if (v[i]) {
      pq.emplace(v[i]->info, v[i]);
    }
  }
  Node dummy(-1);
  Node* cur = &dummy;
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if (it.second->next) {
      pq.emplace(it.second->next->info, it.second->next);
    }
    cur->next = it.second;
    cur = cur->next;
  }
  return dummy.next;
}