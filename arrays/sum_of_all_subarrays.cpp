#include <bits/stdc++.h>

using namespace std;

/* Sum of all subarrays */

// prefix sum
// TC - O(n), SC - O(n)
int64_t sum(vector<int>& v, int n) {
  vector<int64_t> pfx(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pfx[i + 1] = pfx[i] + v[i];
  }
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    ans += pfx[i + 1] * (i + 1) - pfx[i];
  }
  return ans;
}

// math
// TC - O(n), SC - O(1)
int64_t sum(vector<int>& v, int n) {
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    ans += int64_t(v[i]) * (i + 1) * (n - i);
  }
  return ans;
}