#include <bits/stdc++.h>

using namespace std;

/* Missing Number */

// Brute 
// TC - O(n * n), SC - O(1)
int missing_number(vector<int>& v, int n) {
  for (int i = 1; i <= n + 1; i++) {
    bool b = false;
    for (int j = 0; j < n; j++) {
      if (i == v[j]) {
        b = true;
        break;
      }
    }
    if (!b) {
      return i;
    }
  }
  return -1; 
}

// Better (using hashing)
// TC - O(n), SC - O(n)
int missing_number(vector<int>& v, int n) {
  // Size is n + 2 to handle numbers up to n+1
  vector<int> hash(n + 2, 0);
  for (auto& a : v) {
    hash[a]++;
  }
  for (int i = 1; i <= n + 1; i++) {
    if (!hash[i]) {
      return i;
    }
  }
  return -1;
}

// Optimal (using sum)
// TC - O(n), SC - O(1)
int missing_number(vector<int>& v, int n) {
  int64_t s1 = int64_t(n + 1) * (n + 2) / 2;
  int64_t s2 = 0;
  for (auto& a : v) {
    s2 += a;
  }
  return int(s1 - s2);
}

// Optimal (using XOR)
// TC - O(n), SC - O(1)
int missing_number(vector<int>& v, int n) {
  int xr = 0;
  for (int i = 0; i < n; i++) {
    xr ^= (i + 1); // XOR of 1 to n
    xr ^= v[i];  // XOR of array elements
  }
  xr ^= (n + 1);   // include (n + 1) in the range XOR
  return xr;
}