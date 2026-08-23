#include <bits/stdc++.h>

using namespace std;

/* check if the kth bit is set or not */

// left shift
bool check_bit(int64_t n, int k) {
  return n & (int64_t(1) << k);
}

// right shift
bool check_bit(int64_t n, int k) {
  return (n >> k) & int64_t(1);
}