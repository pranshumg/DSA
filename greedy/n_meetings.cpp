#include <bits/stdc++.h>

using namespace std;

/* n meetings in one room */

// TC - O(n), SC - O(n)
int meetings(vector<int>& start, vector<int>& end) {
  vector<pair<int, int>> vp;
  for (int i = 0; i < int(start.size()); i++) {
    vp.emplace_back(start[i], end[i]);
  }
  sort(vp.begin(), vp.end(), [](auto& a, auto& b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  });
  int ans = 0, free = -1;
  for (auto& [st, ed] : vp) {
    if (st > free) {
      ans++;
      free = ed;
    }
  }
  return ans;
}