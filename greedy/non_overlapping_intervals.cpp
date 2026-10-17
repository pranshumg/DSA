#include <bits/stdc++.h>

using namespace std;

/* non overlapping intervals */
// https://leetcode.com/problems/non-overlapping-intervals/

// TC - O(n log n), SC - O(1)
int remove_intervals(vector<vector<int>>& v) {
  sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a[1] < b[1];
  });
  int cnt = 0, ed = INT32_MIN;
  for (auto& a : v) {
    if (a[0] >= ed) {
      cnt++;
      ed = a[1];
    }
  }
  return int(v.size()) - cnt;
}