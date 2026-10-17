#include <bits/stdc++.h>

using namespace std;

/* Reverse words in a string */
// https://leetcode.com/problems/reverse-words-in-a-string/

// TC - O(n), SC - O(n)
string reverse_words(string s) {
  string res = "";
  for (int i = int(s.size()) - 1; i >= 0; i--) {
    string word = "";
    while (i >= 0 && s[i] != ' ') {
      word = s[i--] + word;
    }
    if (!word.empty()) {
      res += " " + word;
    }
  }
  return res.empty() ? "" : res.substr(1);
}