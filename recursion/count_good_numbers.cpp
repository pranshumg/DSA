#include <bits/stdc++.h>

using namespace std;

const int md = int(1e9) + 7;

/* Count Good Numbers */
// https://leetcode.com/problems/count-good-numbers/

int64_t power(int64_t a, int64_t b) {
  if (b == 0) {
    return 1;
  }
  if (b & 1) {
    return (a * power(a, b - 1)) % md;
  }
  return (power((a * a) % md, b / 2)) % md;
}

int count_good_numbers(int64_t n) {
  int64_t ans = (power(5, n / 2) * power(4, n / 2)) % md;
  if (n & 1) ans = (ans * 5) % md;
  return ans;
}