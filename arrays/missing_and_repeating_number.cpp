#include <bits/stdc++.h>

using namespace std;

/* Missing and repeated number */

// Brute 
// TC - O(n * n), SC - O(1)
vector<int> missing_and_repeated(vector<int>& v, int n) {
  int mis = -1, rep = -1;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] == i) {
        cnt++;
      }
    }
    if (cnt == 0) {
      mis = i;
    } else if (cnt == 2) {
      rep = i;
    }
    if (mis != -1 && rep != -1) {
      break;
    }
  }
  return {mis, rep};
}

// Better 
// TC - O(n), SC - O(n)
vector<int> missing_and_repeated(vector<int>& v, int n) {
  int mis = -1, rep = -1;
  vector<int> hash(n + 1, 0);
  for (int i = 0; i < n; i++) {
    hash[v[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (hash[i] == 0) {
      mis = i;
    } else if (hash[i] == 2) {
      rep = i;
    }
    if (mis != -1 && rep != -1) {
      break;
    }
  }
  return {mis, rep};
}

// Optimal 1 (Maths) 
// TC - O(n), SC - O(1)
vector<int> missing_and_repeated(vector<int>& v, int n) {
  int64_t sn = (n * (n + 1)) / 2;
  int64_t s2n = (n * (n + 1) * (2 * n + 1)) / 6;
  int64_t s = 0, s2 = 0;
  for (int i = 0; i < n; i++) {
    s += v[i];
    s2 += int64_t(v[i]) * v[i];
  }
  // val1 = S - SN = (Rep - Miss)
  int64_t val1 = s - sn; 
  // val2 = S2 - S2N = (Rep^2 - Miss^2)
  int64_t val2 = s2 - s2n;
  // val2 / val1 = (Rep + Miss)
  val2 = val2 / val1;
  // x = Rep - Miss, y = Rep + Miss
  // Rep = (x + y) / 2
  int64_t rep = (val1 + val2) / 2;
  int64_t mis = rep - val1;
  return {int(mis), int(rep)};
}

// Optimal 2 (XOR) (
// TC - O(n), SC - O(1)
vector<int> missing_and_repeated(vector<int>& v, int n) {
  int xr = 0;
  // Step 1: XOR all array elements and numbers 1 to N
  for (int i = 0; i < n; i++) {
    xr ^= v[i];
    xr ^= (i + 1);
  }
  // xr now contains (missing ^ repeated)
  // Step 2: Find the rightmost set bit
  // This bit is 1 in one number and 0 in the other
  int bit_no = xr & ~(xr - 1); 
  int zero = 0, one = 0;
  // Step 3: Bucket numbers into two groups based on that bit
  for (int i = 0; i < n; i++) {
    // Check array elements
    if ((v[i] & bit_no) != 0) {
      one ^= v[i];
    } else {
      zero ^= v[i];
    }
    // Check numbers 1 to N
    if (((i + 1) & bit_no) != 0) {
      one ^= (i + 1);
    } else {
      zero ^= (i + 1);
    }
  }
  // zero and one are now the two unique numbers (missing and repeated).
  // Step 4: Identify which is which by scanning the array
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == zero) {
      cnt++;
    }
  }
  if (cnt == 2) {
    return {one, zero}; // zero is repeated, one is missing
  } 
  return {zero, one};
}