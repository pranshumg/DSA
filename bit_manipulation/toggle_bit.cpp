#include <bits/stdc++.h>

using namespace std;

/* toggle the kth bit */

void toggle_bit(int64_t& n, int k) {
  n ^= (uint64_t(1) << k);
}