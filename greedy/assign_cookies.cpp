#include <bits/stdc++.h>

using namespace std;

/* assign cookies */
// https://leetcode.com/problems/assign-cookies/

// TC - O(n log n), SC - O(1) where n = max(number of children, number of cookies)
int find_content_children(vector<int>& g, vector<int>& s) {
  sort(g.rbegin(), g.rend());
  sort(s.rbegin(), s.rend());
  int ans = 0;
  for (int i = 0, j = 0; i < int(g.size()) && j < int(s.size()); i++) {
    if (s[j] >= g[i]) {
      ans++;
      j++;
    }
  }
  return ans;
}