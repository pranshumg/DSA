#include <bits/stdc++.h>

using namespace std;

/* asteroid collision */
// https://leetcode.com/problems/asteroid-collision/

// TC - O(n), SC - O(n)
vector<int> asteroid_collision(vector<int>& v) {
  vector<int> res;
  for (int i = 0; i < int(v.size()); i++) {
    while (!res.empty()) {
      if (v[i] < 0 && res.back() > 0 && abs(v[i]) > res.back()) {
        res.pop_back();
      } else {
        break;
      }
    }
    if (!res.empty() && v[i] < 0 && res.back() > 0) {
      if (abs(v[i]) == res.back()) {
        res.pop_back();
      }
    } else {
      res.push_back(v[i]);
    }
  }
  return res;
}