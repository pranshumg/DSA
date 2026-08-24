#include <bits/stdc++.h>

using namespace std;

/* single number 3 */
// https://leetcode.com/problems/single-number-iii/

// TC - O(n), SC - O(1)
vector<int> single_number(vector<int>& v) {
  int xr = 0;
  for (int i : v) {
    xr ^= i;
  }
  int rightmost = xr & -xr;
  int b1 = 0, b2 = 0;
  for (int i : v) {
    if (rightmost & i) {
      b1 ^= i;
    } else {
      b2 ^= i;
    }
  }
  return {b1, b2};
}