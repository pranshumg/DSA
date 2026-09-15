#include <bits/stdc++.h>

using namespace std;

/* reverse bits */
// https://leetcode.com/problems/reverse-bits/

// TC - O(1), SC - O(1)
int reverse_bits(int n) {
  int res = 0;
  for (int i = 0; i < 32; i++) {
    if ((n >> i) & 1) {
      res |= 1 << (31 - i);
    } 
  }
  return res;
}

// TC - O(1), SC - O(1)
int reverse_bits(int n) {
  int res = 0;
  for (int i = 0; i < 32; i++) {
    res <<= 1;
    res |= (n & 1);
    n >>= 1;
  }
  return res;
}