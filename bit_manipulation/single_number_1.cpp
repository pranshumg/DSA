#include <bits/stdc++.h>

using namespace std;

/* single number 1 */
// https://leetcode.com/problems/single-number/

// TC - O(n log n), SC - O(n)
int single_number(vector<int>& v) {
  map<int, int> mp;
  for (int i : v) {
    mp[i]++;
  }
  for (auto& [el, cnt] : mp) {
    if (cnt == 1) {
      return el;
    }
  } 
  return -1;
}

// TC - O(n log n), SC - O(1)
int single_number(vector<int>& v) {
  sort(v.begin(), v.end());
  for (int i = 0; i < int(v.size()) - 1; i += 2) {
    if (v[i] != v[i + 1]) {
      return v[i];
    } 
  }
  return v.back();
}

// TC - O(n), SC - O(1)
int single_number(vector<int>& v) {
  int xr = 0;
  for (int i : v) {
    xr ^= i;
  }
  return xr;
}