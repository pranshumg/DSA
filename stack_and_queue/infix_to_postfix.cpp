#include <bits/stdc++.h>

using namespace std;

/* infix to postfix conversion */

int priority(char c) {
  if (c == '^') return 3;
  if (c == '*' || c == '/') return 2;
  if (c == '+' || c == '-') return 1;
  return -1;
}

// TC - O(n), SC - O(n)
string infix_to_postfix(string s) {
  stack<char> sk;
  string ans = "";
  for (int i = 0; i < int(s.size()); i++) {
    if (isalnum(s[i])) {
      ans += s[i];
      continue;
    }
    if (s[i] == '(') {
      sk.push(s[i]);
      continue;
    } 
    if (s[i] == ')') {
      while (!sk.empty() && sk.top() != '(') {
        ans += sk.top();
        sk.pop();
      }
      if (!sk.empty()) sk.pop();
      continue;
    }
    while (!sk.empty() && ((s[i] == '^' && priority(s[i]) < priority(sk.top())) || (s[i] != '^' && priority(s[i]) <= priority(sk.top())))) {
      ans += sk.top();
      sk.pop();
    }
    sk.push(s[i]);
  }
  while (!sk.empty()) {
    ans += sk.top();
    sk.pop();
  }
  return ans;
}