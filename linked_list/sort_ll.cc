#include <bits/stdc++.h>

using namespace std;

/* Sort a linked list */
// https://leetcode.com/problems/sort-list/description/

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
Node* sort_ll(Node* head) {
  vector<int> v;
  Node* cur = head;
  while (cur) {
    v.push_back(cur->info);
    cur = cur->next;
  } 
  sort(v.begin(), v.end());
  cur = head;
  for (int i = 0; i < int(v.size()); i++) {
    cur->info = v[i];
    cur = cur->next;
  }
  return head;
}

Node* merge(Node* a, Node* b) {
  Node* tmp_a = a;
  Node* tmp_b = b;
  Node dummy(-1);
  Node* cur = &dummy;
  while (tmp_a && tmp_b) {
    if (tmp_a->info <= tmp_b->info) {
      cur->next = tmp_a;
      tmp_a = tmp_a->next;
    } else {
      cur->next = tmp_b;
      tmp_b = tmp_b->next;
    }
    cur = cur->next;
  }
  cur->next = tmp_a ? tmp_a : tmp_b;
  return dummy.next;
}

Node* middle(Node* head) {
  if (!head || !head->next || !head->next->next) {
    return head;
  }
  Node* slow = head;
  Node* fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

Node* merge_sort(Node* head) {
  if (!head || !head->next) {
    return head;
  }
  Node* mid = middle(head);
  Node* nxt = mid->next;
  mid->next = nullptr;
  head = merge_sort(head);
  nxt = merge_sort(nxt);
  return merge(head, nxt);
}

// TC - O(n log n), SC - O(n log n)
Node* sort_ll(Node* head) {
  return merge_sort(head);
}