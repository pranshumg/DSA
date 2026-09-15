#include <bits/stdc++.h>

using namespace std;

/* prefix to infix conversion */
  
// TC - O(n), SC - O(n)
string prefix_to_infix(string s) {
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
    sk.push('(' + top1 + c + top2 + ')');
  }
  return sk.top();
}