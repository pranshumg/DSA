#include <bits/stdc++.h>

using namespace std;

/* power set */ 
// https://leetcode.com/problems/subsets/

// TC - O(n*2^n), SC - O(n)
vector<vector<int>> power_set(vector<int>& v) {
  vector<vector<int>> res;
  for (int mask = 0; mask < (1 << int(v.size())); mask++) {
    vector<int> tmp;
    for (int i = 0; i < int(v.size()); i++) {
      if (mask & (1 << i)) {
        tmp.push_back(v[i]);
      }
    }
    res.push_back(tmp);
  }
  return res;
}