#include <bits/stdc++.h>

using namespace std;

/* decimal to binary */

// TC - O(log n), SC - O(log n)
string dec_to_bin(int n) {
  string res = "";
  while (n) {
    int rem = n % 2;
    res = char('0' + rem) + res;
    n >>= 1;
  }
  return res;
}