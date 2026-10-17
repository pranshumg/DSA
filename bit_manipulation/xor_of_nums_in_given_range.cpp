#include <bits/stdc++.h>

using namespace std;

/* xor of numbers in a given range */

// TC - O(n), SC - O(n)
int xor_of_numbers(int l, int r) {
  if (l > r) {
    return xor_of_numbers(r, l);
  }
  vector<int> pref(r + 1, 0);
  for (int i = 1; i <= r; i++) {
    pref[i] = pref[i - 1] ^ i;
  }
  if (l == 0) {
    return pref[r];
  }
  return pref[r] ^ pref[l - 1];
}

int xor_4(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}

// TC - O(1), SC - O(1);
int xor_of_numbers(int l, int r) {
  if (l > r) {
    return xor_of_numbers(r, l);
  }
  if (l == 0) {
    return xor_4(r);
  }
  return xor_4(l - 1) ^ xor_4(r);
}