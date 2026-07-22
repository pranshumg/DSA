#include <bits/stdc++.h>

using namespace std;

/* find the element at given row and column */

// TC - O(r), SC - O(1)
int64_t nCr(int n, int r) {
  int64_t res = 1;
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}