#include <bits/stdc++.h>

using namespace std;

/* binary to decimal */

// TC - O(n) where n is the length of string, SC - O(1)
int64_t bin_to_dec(string& s) {
  int64_t res = 0, p2 = int64_t(1);
  for (int i = int(s.size()) - 1; i >= 0; i--) {
    res += p2 * (s[i] - '0');
    p2 <<= 1;
  }
  return res;
}