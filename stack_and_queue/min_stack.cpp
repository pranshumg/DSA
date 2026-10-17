#include <bits/stdc++.h>

using namespace std;

/* min stack */
// https://leetcode.com/problems/min-stack/

// TC - O(1), SC - O(n)
class min_stack {
private:
  stack<int> sk, mn;
  
public:
  void push(int val) {
    if (mn.empty() || mn.top() >= val) {
      mn.push(val);
    }
    sk.push(val);
  }
  
  void pop() {
    if (sk.top() == mn.top()) {
      mn.pop();
    }
    sk.pop();
  }
  
  int top() {
    return sk.top();
  }
  
  int get_min() {
    return mn.top();
  }
};

// TC - O(1), SC - O(n)
class min_stack {
private:
  stack<int64_t> sk;
  int64_t mn = INT64_MAX;

public:
  void push(int val) {
    if (sk.empty()) {
      sk.push(val);
      mn = val;
      return;
    }
    if (val < mn) {
      sk.push(int64_t(2) * val - mn);
      mn = val;
      return;
    }
    sk.push(val);
  }

  void pop() {
    if (sk.top() < mn) {
      mn = int64_t(2) * mn - sk.top();
    }
    sk.pop();
  }

  int top() {
    if (sk.top() < mn) {
      return mn;
    }
    return sk.top();
  }

  int get_min() {
    return mn;
  }
};