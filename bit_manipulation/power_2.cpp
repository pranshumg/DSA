#include <bits/stdc++.h>

using namespace std;

/* power of 2 */
// https://leetcode.com/problems/power-of-two/

// TC - O(1), SC - O(1)
bool is_power_of_2(int n) {
  if (n == 0 || n == INT_MIN || n == INT_MAX) {
    return false;
  }
  return !(n & (n - 1));
}