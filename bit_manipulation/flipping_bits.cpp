#include <bits/stdc++.h>

using namespace std;

/* flipping bits */

// TC - O(1), SC - O(1)
unsigned flip(unsigned n) {
  return ~n;
}

// TC - O(1), SC - O(1)
unsigned flip(int n) {
  return n ^ ~unsigned(0);
}