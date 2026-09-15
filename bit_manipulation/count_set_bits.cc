#include <bits/stdc++.h>

using namespace std;

/* count set bits */
// https://leetcode.com/problems/number-of-1-bits/

// TC - O(log n), SC - O(1)
int count_set_bits(int n) {
  int cnt = 0;
  while (n) {
    cnt += n & 1;
    n >>= 1;
  }
  return cnt;
}

// Brian Kernighan’s Algorithm
// TC - O(k) where k = number of set bits, SC - O(1) 
int count_set_bits(int n) {
  int cnt = 0;
  while (n) {
    n &= (n - 1);
    cnt++;
  }
  return cnt;
}

// TC - O(1), SC - O(1)
int count_set_bits(int n) {
  return int(popcount(unsigned(n)));
}