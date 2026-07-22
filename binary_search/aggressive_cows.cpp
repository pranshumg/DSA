#include <bits/stdc++.h>

using namespace std;

/* Aggressive cows */

bool check(vector<int>& v, int n, int dist, int cows) {
  int cnt = 1, prev = v[0];  
  for (int i = 1; i < n; i++) {
    if (v[i] - prev >= dist) {
      cnt++;    
      prev = v[i];  
    }
    if (cnt >= cows) return true;
  }
  return false;
}

// TC - O(n log n + n * log(max(v) - min(v))),  SC - O(1)
int distance(vector<int>& v, int n, int cows) {
  sort(v.begin(), v.end());
  int low = 1, high = v[n - 1] - v[0];
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(v, n, mid, cows)) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}