#include <bits/stdc++.h>

using namespace std;

/* Remove outermost parentheses */
// https://leetcode.com/problems/remove-outermost-parentheses/

// TC - O(n), SC - O(n)
string remove_outermost_parentheses(string s) {
  string res = "";
  int cnt = 0;
  for (char c : s) {
    if (c == '(') {
      if (cnt > 0) res += c;
      cnt++;
    } else {
      cnt--;
      if (cnt > 0) res += c;
    }
  }
  return res;
}