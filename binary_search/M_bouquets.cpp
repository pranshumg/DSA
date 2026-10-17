#include <bits/stdc++.h>

using namespace std;

/* Minimum days to make m bouquets */
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

int count(vector<int>& v, int day, int k) {
  int tot = 0, cnt = 0;
  for (int i : v) {
    if (i <= day) {
      ++cnt;
      if (cnt == k) {
        tot++;
        cnt = 0; 
      }
    } else {
      cnt = 0;
    }
  }
  return tot;
}

// TC - O(n * log(max(v) - min(v))), SC - O(1)
int min_days(vector<int>& v, int n, int m, int k) {
  if (int64_t(m) * k > n) return -1;
  int low = *min_element(v.begin(), v.end());
  int high = *max_element(v.begin(), v.end());
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (count(v, mid, k) >= m) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}