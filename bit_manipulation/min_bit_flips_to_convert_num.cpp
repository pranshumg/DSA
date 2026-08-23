#include <bits/stdc++.h>

using namespace std;

/* minimum bit flips to convert number */
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

// TC - O(1), SC - O(1)
int min_bit_flips(int start, int goal) {
  return int(popcount(unsigned(start ^ goal)));
}