#include <bits/stdc++.h>

using namespace std;

/* Longest common prefix */
// https://leetcode.com/problems/longest-common-prefix/

// TC - O(n log n * m), SC - O(1) where m is the average string length
string longest_common_prefix(vector<string>& v) {
  sort(v.begin(), v.end());
  string res = "";
  for (int i = 0; i < int(v[0].size()); i++) {
    if (v[0][i] != v[int(v.size()) - 1][i]) {
      break;
    } 
    res += v[0][i];
  }
  return res;
}