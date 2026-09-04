#include <bits/stdc++.h>

using namespace std;

/* trapping rainwater */
// https://leetcode.com/problems/trapping-rain-water/

// TC - O(n), SC - O(n)
int trap(vector<int>& v) {
  vector<int> suf(int(v.size()) + 1, 0);
  for (int i = int(v.size()) - 1; i >= 0; i--) {
    suf[i] = max(suf[i + 1], v[i]);
  }
  int ans = 0, pref = 0;
  for (int i = 0; i < int(v.size()); i++) {
    if (v[i] < pref && v[i] < suf[i + 1]) {
      ans += min(pref, suf[i + 1]) - v[i];
    }
    pref = max(pref, v[i]);
  }
  return ans;
}

// TC - O(n), SC - O(1)
int trap(vector<int>& v) {
  int ans = 0;
  int l = 0, r = int(v.size()) - 1;
  int l_mx = 0, r_mx = 0;
  while (l < r) {
    if (v[l] <= v[r]) {
      l_mx = max(l_mx, v[l]);
      ans += l_mx - v[l++];
    } else {
      r_mx = max(r_mx, v[r]);
      ans += r_mx - v[r--];
    }
  }
  return ans;
}