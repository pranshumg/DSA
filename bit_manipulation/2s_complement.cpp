#include <bits/stdc++.h>

using namespace std;
  
/* 2's complement */

// mathematical approach
// TC - O(1), SC - O(1)
int64_t twos_complement(int64_t n) {
  return -n;
}

// bitwise approach (preferred & canonical)
// TC - O(1), SC - O(1)
int64_t twos_complement(int64_t n) {
  return ~n + 1;
}