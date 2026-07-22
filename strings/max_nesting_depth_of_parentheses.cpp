#include <bits/stdc++.h>

using namespace std;

/* Maximum nesting depth of parentheses */
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

// TC - O(n), SC - O(1)
int max_depth(string s) {
  int ans = 0, cnt = 0;
  for (char c : s) {
    if (c == '(') cnt++;
    else if(c == ')') cnt--;
    ans = max(ans, cnt);
  }
  return ans;
}