#include <bits/stdc++.h>

using namespace std;

/* xor mod 4 trick */

int xor_4(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}