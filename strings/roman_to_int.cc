#include <bits/stdc++.h>

using namespace std;

/* Roman to integer */
// https://leetcode.com/problems/roman-to-integer/

// TC - O(n), SC - O(1)
int roman_to_int(string s) {
  map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  int ans = 0;
  for (int i = 0; i < int(s.size()); i++) {
    ans += mp[s[i]];
    if (i && mp[s[i - 1]] < mp[s[i]]) {
      ans -= 2 * mp[s[i - 1]];
    }
  }
  return ans;
}