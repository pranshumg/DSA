#include <bits/stdc++.h>

using namespace std;

/* remove the last set bit */

void remove_bit(int64_t& n) {
  n &= (n - 1);
}