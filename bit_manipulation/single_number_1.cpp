#include <bits/stdc++.h>

using namespace std;

/* single number 1 */
// https://leetcode.com/problems/single-number/

// TC - O(n), SC - O(1)
int single_number(vector<int>& v) {
  int xr = 0;
  for (int i : v) {
    xr ^= i;
  }
  return xr;
}