#include <bits/stdc++.h>

using namespace std;

/* postfix to prefix conversion */

// TC - O(n), SC - O(n)
string postfix_to_prefix(string s) {
  stack<string> sk;
  for (char c : s) {
    if (isalnum(c)) {
      sk.push(string(1, c));
      continue;
    }
    string top1 = sk.top();
    sk.pop();
    string top2 = sk.top();
    sk.pop();
    sk.push(c + top2 + top1);
  }
  return sk.top();
}