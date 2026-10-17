#include <bits/stdc++.h>

using namespace std;

/* Palindrome partitioning */
// https://leetcode.com/problems/palindrome-partitioning/
  
bool is_palindrome(string& s, int l, int r) {
  while (l < r) {
    if (s[l++] != s[r--]) {
      return false;
    }
  }   
  return true;
}

void solve(int idx, string& s, vector<string>& tmp, vector<vector<string>>& res) {
  if (idx == int(s.size())) {
    res.push_back(tmp);
    return;
  }
  for (int i = idx; i < int(s.size()); i++) {
    if (is_palindrome(s, idx, i)) {
      tmp.push_back(s.substr(idx, i - idx + 1));
      solve(i + 1, s, tmp, res);
      tmp.pop_back();
    }
  }
}

// TC - O(n * 2^n), SC - O(n * 2^n) 
vector<vector<string>> partition(string s) {
  vector<vector<string>> res;
  vector<string> tmp;
  solve(0, s, tmp, res);
  return res;
}