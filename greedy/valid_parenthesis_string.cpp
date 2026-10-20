#include <bits/stdc++.h>

using namespace std;

/* valid parenthesis string */
// https://leetcode.com/problems/valid-parenthesis-string/

// TC - O(n), SC - O(n)
bool check(string s) {
  stack<int> open, asterisk;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == '(') {
      open.push(i);
    } else if (s[i] == '*') {
      asterisk.push(i);
    } else {
      if (!open.empty()) {
        open.pop();
      } else if (!asterisk.empty()) {
        asterisk.pop();
      } else {
        return false;
      }
    }
  }
  while (!open.empty() && !asterisk.empty()) {
    if (open.top() > asterisk.top()) {
      return false;
    }
    open.pop();
    asterisk.pop();
  }
  return open.empty();
}