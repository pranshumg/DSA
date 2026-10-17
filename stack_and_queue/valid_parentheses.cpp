#include <bits/stdc++.h>

using namespace std;

/* valid parentheses */
// https://leetcode.com/problems/valid-parentheses/

// TC - O(n), SC - O(n)
bool is_valid(string s) {
  stack<char> sk;
  for (char c : s) {
    if (sk.empty() || c == '(' || c == '[' || c == '{') {
      sk.push(c);
      continue;
    }
    char top = sk.top();
    sk.pop();
    if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
      return false;
    }
  }
  return sk.empty();
}