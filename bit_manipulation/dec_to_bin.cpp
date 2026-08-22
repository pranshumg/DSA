#include <bits/stdc++.h>

using namespace std;

/* decimal to binary */

// TC - O(log n), SC - O(log n)
string dec_to_bin(int n) {
  if (n == 0) {
    return "0";
  }
  string res = "";
  while (n) {
    res += (n & 1 ? '1' : '0');
    n >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}