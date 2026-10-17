#include <bits/stdc++.h>

using namespace std;

/* 1's complement */

// mathematical approach
// TC - O(1), SC - O(1)
int64_t ones_complement(int64_t n) {
  return -(n + 1);
}

// bitwise approach (preferred & canonical)
// TC - O(1), SC - O(1)
int64_t ones_complement(int64_t n) {
  return ~n;
}