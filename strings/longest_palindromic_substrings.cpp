#include <bits/stdc++.h>

using namespace std;

/* Longest palindromic substrings */
// https://leetcode.com/problems/longest-palindromic-substring/

// TC - O(n * n * n), SC - O(1)
string longest_palindrome(string s) {
  auto is_palindrome = [&](int l, int r) -> bool {
    while (l < r) {
      if (s[l++] != s[r--]) return false;
    }
    return true;
  };
  int l = 0, r = 0;
  for (int i = 0; i < int(s.size()); i++) {
    for (int j = int(s.size()) - 1; j >= i; j--) {
      if (is_palindrome(i, j)) {
        if (j - i > r - l) {
          l = i;
          r = j;
        }
        break;
      }
    }
  }
  return s.substr(l, r - l + 1);
}