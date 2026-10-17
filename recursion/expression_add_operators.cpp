#include <bits/stdc++.h>

using namespace std;

/* Expression add operators */
// https://leetcode.com/problems/expression-add-operators/

void solve(int idx, int64_t res, int64_t prev, int target, string expression, string& num, vector<string>& ans) {
  if (idx == int(num.size())) {
    if (res == target) {
      ans.push_back(expression);
    }
    return;
  }
  string cur = "";
  int64_t val = 0;
  for (int i = idx; i < int(num.size()); i++) {
    if (i > idx && num[idx] == '0') return;
    cur += num[i];
    val = val * 10 + num[i] - '0';
    if (idx == 0) {
      solve(i + 1, val, val, target, cur, num, ans);
    } else {
      solve(i + 1, res + val, val, target, expression + "+" + cur, num, ans);
      solve(i + 1, res - val, -val, target, expression + "-" + cur, num, ans);
      solve(i + 1, res - prev + prev * val, prev * val, target, expression + "*" + cur, num, ans);
    }
  }
}

// TC - O(4^n), SC - O(n)
vector<string> add_operators(string num, int target) {
  vector<string> ans;
  solve(0, 0, 0, target, "", num, ans);
  return ans;
}