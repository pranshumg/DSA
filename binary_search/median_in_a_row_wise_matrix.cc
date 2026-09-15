#include <bits/stdc++.h>

using namespace std;

/* Median in a row wise sorted matrix */

// TC - O(log(max(v) - min(v)) * n log m), SC - O(1)
int median(vector<vector<int>>& v, int n, int m) {
  int low = 1e9, high = -1e9;
  for (int i = 0; i < n; ++i) {
    low = min(low, v[i][0]);
    high = max(high, v[i][m - 1]);
  }
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      auto it = upper_bound(v[i].begin(), v[i].end(), mid);
      cnt += it - v[i].begin();
    }
    if (cnt > (n * m) / 2) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}