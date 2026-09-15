#include <bits/stdc++.h>

using namespace std;

/* Reverse stack using recursion */

// TC - O(n * n), SC - O(n)

void insert(stack<int>& sk, int el) {
  if (sk.empty()) {
    sk.push(el);
    return;
  }
  int top = sk.top();
  sk.pop();
  insert(sk, el);
  sk.push(top);
}

void reverse_stack(stack<int>& sk) {
  if (!sk.empty()) {
    int top = sk.top();
    sk.pop();
    reverse_stack(sk);
    insert(sk, top);
  }
}