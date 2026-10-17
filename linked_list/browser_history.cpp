#include <bits/stdc++.h>

using namespace std;

// Design browser history
// https://leetcode.com/problems/design-browser-history/

class Node {
public:
  string info;
  Node* next;
  Node* prev;

  Node(string info) {
    this->info = info; 
    this->next = nullptr;
    this->prev = nullptr;
  }

  Node(string info, Node* next, Node* prev) {
    this->info = info;  
    this->next = next;
    this->prev = prev;
  }
};

class browser_history {
public:
  Node* cur;
  
  browser_history(string homepage) {
    cur = new Node(homepage);
  }

  void visit(string url) {
    cur->next = new Node(url, nullptr, cur);
    cur = cur->next;
  } 

  string back(int steps) {
    while (steps--) {
      if (!cur->prev) {
        return cur->info;
      }
      cur = cur->prev;
    }
    return cur->info;
  }

  string forward(int steps) {
    while (steps--) {
      if (!cur->next) {
        return cur->info;
      }
      cur = cur->next;
    }
    return cur->info;
  }
};