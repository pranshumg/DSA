#include <bits/stdc++.h>

using namespace std;

/* rightmost set bit */

// TC - O(1), SC - O(1)
int rightmost_set_bit(int n) {
  return n & -n;
}