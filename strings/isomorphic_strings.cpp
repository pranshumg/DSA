#include <bits/stdc++.h>

using namespace std;

/* Isomorphic Strings */
// https://leetcode.com/problems/isomorphic-strings/

// TC - O(n), SC - O(1)
bool is_isomorphic(string s, string t) {
  if (int(s.size()) != int(t.size())) {
    return false;
  }
  map<char, char> mp_s, mp_t;
  for (int i = 0; i < int(s.size()); i++) {
    if (mp_s.count(s[i]) && mp_s[s[i]] != t[i]) return false;
    if (mp_t.count(t[i])  && mp_t[t[i]] != s[i]) return false;
    mp_s[s[i]] = t[i];
    mp_t[t[i]] = s[i];
  }
  return true;
}