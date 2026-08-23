#include <bits/stdc++.h>

using namespace std; 

/* set the kth bit */

void set_bit(int64_t& n, int k) {
  n |= (int64_t(1) << k);
}