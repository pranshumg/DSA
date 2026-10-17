#include <bits/stdc++.h>

using namespace std;

/* Optimal LCM function using the relation: LCM(n, m) = (n * m) / GCD(n, m) */

// TC - O(log(min(n, m))), SC - O(1)
int gcd(int n, int m) {
  while (n > 0 && m > 0) {
    n > m ? n %= m : m %= n;
  }
  return (n == 0 ? m : n);
}

int lcm(int n, int m) {
  // Cast to int64_t to prevent overflow during multiplication
  int64_t prod = int64_t(n * m);
  return prod / gcd(n, m);
}