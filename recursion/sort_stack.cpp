#include <bits/stdc++.h>

using namespace std;

/* Sort a stack using recursion */

// TC - O(n * n), SC - O(n)

void insert(stack<int>& sk, int el) {
  if (sk.empty() || sk.top() < el) {
    sk.push(el);
    return;
  }
  int top = sk.top();
  sk.pop();
  insert(sk, el);
  sk.push(top);   
}

void sort_stack(stack<int>& sk) {
  if (!sk.empty()) {
    int top = sk.top();
    sk.pop();
    sort_stack(sk);
    insert(sk, top);
  }
}