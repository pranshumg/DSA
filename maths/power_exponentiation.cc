#include <bits/stdc++.h>

using namespace std;

/* Power exponentiation */
// https://leetcode.com/problems/powx-n/

// TC - O(log n), SC - O(1)
int64_t power(int64_t x, int n) {
  int64_t ans = 1;
  // Use int64_t to safely handle n = INT_MIN because abs(INT_MIN) overflows int
  int64_t m = abs(int64_t(n));
  while (m) {
    if (m & 1) {
      ans *= x;
    }
    x *= x;
    m >>= 1;
  }
  if (n < 0) {
    ans = 1 / ans;
  }
  return ans;
}