#include <bits/stdc++.h>

using namespace std;

/* clear the kth bit */

void clear_bit(int64_t& n, int k) {
  n &= ~(uint64_t(1) << k);
}