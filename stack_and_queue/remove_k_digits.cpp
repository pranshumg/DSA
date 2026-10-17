#include <bits/stdc++.h>

using namespace std;

/* remove k digits */
// https://leetcode.com/problems/remove-k-digits/

// TC - O(n), SC - O(n)
string remove_k_digits(string& s, int k) {
  stack<char> sk;
  for (int i = 0; i < int(s.size()); i++) {
    while (!sk.empty() && k && sk.top() - '0' > s[i] - '0') {
      sk.pop();
      k--;
    }
    sk.push(s[i]);
  }
  while (k--) {
    sk.pop();
  }
  string res = "";
  while (!sk.empty()) {
    res += sk.top();
    sk.pop();
  }
  if (res.empty()) {
    return "0";
  }
  reverse(res.begin(), res.end());
  for (int i = 0; i < int(res.size()); i++) {
    if (res[i] != '0') {
      return res.substr(i, int(res.size()) - i + 1);
    }
  }
  return "0";
}