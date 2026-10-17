#include <bits/stdc++.h>

using namespace std;

/* Pow(x, n) */
// https://leetcode.com/problems/powx-n/

// TC - (log n), SC - O(log n)
int64_t power(int64_t x, int n) {
  if (n == 0) {
    return 1;
  }
  if (n & 1) return x * power(x, n - 1);
  return power(x * x, n / 2);
}