#include <bits/stdc++.h>

using namespace std;

/* infix to prefix conversion */

int priority(char c) {
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  if (c == '+' || c == '-') return 1;
  return -1;
}

// TC - O(n), SC - O(n)
string infix_to_prefix(string s) {
  reverse(s.begin(), s.end());
  for (char& c : s) {
    if (c == '(') c = ')';
    else if (c == ')') c = '(';
  }
  stack<char> sk;
  string ans = "";
  for (char c : s) {
    if (isalnum(c)) {
      ans += c;
      continue;
    }
    if (c == '(') {
      sk.push(c);
      continue;
    }
    if (c == ')') {
      while (!sk.empty() && sk.top() != '(') {
        ans += sk.top();
        sk.pop();
      }
      if (!sk.empty()) sk.pop();
      continue;
    }
    while (!sk.empty() && ((c == '^' && priority(c) <= priority(sk.top())) || (c != '^' && priority(c) < priority(sk.top())))) {
      ans += sk.top();
      sk.pop();
    }
    sk.push(c);
  }
  while (!sk.empty()) {
    ans += sk.top();
    sk.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}