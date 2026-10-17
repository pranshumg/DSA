#include <bits/stdc++.h>

using namespace std;

/* maximizing xor */
// https://www.hackerrank.com/challenges/maximizing-xor/problem

// TC - O(1), SC - O(1)
int max_xor(int l, int r) {
  if (l == r) {
    return 0;
  }
  int pos = 32 - countl_zero(unsigned(l ^ r));
  return (uint64_t(1) << pos) - 1;
}