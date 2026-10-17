#include <bits/stdc++.h>

using namespace std;

/* prefix to postfix conversion */

// TC - O(n), SC - O(n)
string prefix_to_postfix(string s) {
  stack<string> sk;
  for (int i = int(s.size()) - 1; i >= 0; i--) {
    char c = s[i];
    if (isalnum(c)) {
      sk.push(string(1, c));
      continue;
    }
    string top1 = sk.top();
    sk.pop();
    string top2 = sk.top();
    sk.pop();
    sk.push(top1 + top2 + c);
  }
  return sk.top();
}