#include <bits/stdc++.h>

using namespace std;
  
/* 2's complement */

// mathematical approach
int64_t twos_complement(int64_t n) {
  return -n;
}

// bitwise approach (preferred & canonical)
int64_t twos_complement(int64_t n) {
  return ~n + 1;
}