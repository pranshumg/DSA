#include <bits/stdc++.h>

using namespace std;

/* 1's complement */

// mathematical approach
int64_t ones_complement(int64_t n) {
  return -(n + 1);
}

// bitwise approach (preferred & canonical)
int64_t ones_complement(int64_t n) {
  return ~n;
}