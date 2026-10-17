#include <bits/stdc++.h>

using namespace std;

/* LRU Cache */
// https://leetcode.com/problems/lru-cache/

class Node {
public:
  int info;
  Node* next;
  Node* prev;

  Node(int info, Node* next, Node* prev) {
    this->info = info;
    this->next = next;
    this->prev = prev;
  }
};

class LRU_Cache {
private:
  unordered_map<int, int> ump;
  unordered_map<int, Node*> ptr;
  int sz;
  Node* head;
  Node* cur;

public:
  LRU_Cache(int capacity) {
    head = new Node(-1, nullptr, nullptr);
    cur = head;
    sz = capacity;
  }

  void delete_node(Node* cur) {
    Node* del = cur;
    Node* nxt = cur->next;
    del->prev->next = nxt;
    if (nxt) {
      nxt->prev = del->prev;
    }
    delete del;
  }

  int get(int key) {
    if (cur->info == key) {
      return ump[key];
    }
    if (ump.count(key)) {
      delete_node(ptr[key]);
      cur->next = new Node(key, nullptr, cur);
      cur = cur->next;
      ptr[key] = cur;
      return ump[key];
    }
    return -1;
  }

  void put(int key, int value) {
    if (cur->info == key) {
      ump[key] = value;
      return;
    }
    if (ump.count(key)) {
      delete_node(ptr[key]);
    } else if (int(ump.size()) == sz) {
      int tmp = head->next->info;
      if (sz == 1) {
        cur->info = key;
      } else {
        delete_node(head->next);
        cur->next = new Node(key, nullptr, cur);
        cur = cur->next;
      }
      ump.erase(tmp);
      ptr.erase(tmp);
      ump[key] = value;
      ptr[key] = cur;
      return;
    }
    cur->next = new Node(key, nullptr, cur);
    cur = cur->next;
    ump[key] = value;
    ptr[key] = cur;
  }
};