#include <bits/stdc++.h>

using namespace std;

/* Rightmost set bit */

// TC - O(1), SC - O(1)
int rightmost_set_bit(int n) {
  if (n == 0) {
    return 0;
  }
  return n ^ (n & (n - 1));
}

// TC - O(1), SC - O(1)
int rightmost_set_bit(int n) {
  return n & -n;
}

// TC - O(1), SC - O(1)
int rightmost_set_bit(int n) {
  if (n == 0) {
    return 0;
  }
  return 1 << countr_zero(unsigned(n));
}