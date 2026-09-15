#include <bits/stdc++.h>

using namespace std;


/* String to Integer (atoi) */
// https://leetcode.com/problems/string-to-integer-atoi/

bool is_valid(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '.')) {
    return false;
  }
  return true;
}

void solve(int64_t& res, string s, int i, int n, bool sign, bool& neg, bool empty) {
  if (i >= n || !is_valid(s[i]) || (s[i] == ' ' && (empty || sign))) return;
  if (res > INT_MAX) return;
  if (s[i] == '-' || s[i] == '+') {
    if (sign || empty) return;
    else {
      if (s[i] == '-') neg = true;
      sign = true;
    }
  } else if (isdigit(s[i])) {
    res = res * 10 + (s[i] - '0');
    empty = true;
  }
  solve(res, s, i + 1, n, sign, neg, empty);
}

// TC - O(n), SC - O(n)
int atoi(string s) {
  int64_t res = 0;
  bool neg = false;
  solve(res, s, 0, int(s.size()), false, neg, false);
  if (neg) res *= -1;
  if (res > INT_MAX) return INT_MAX;
  if (res < INT_MIN) return INT_MIN;
  return res;
}