#include <bits/stdc++.h>

using namespace std;

/* shortest job first (sjf) cpu scheduling */

// TC - O(n log n), SC - O(1) where n = number of processes
int sjf(vector<int>& v) {
  sort(v.begin(), v.end());
  int wt = 0, tot = 0;
  for (int i = 0; i < int(v.size()); i++) {
    tot += wt;
    wt += v[i];
  }
  return tot / int(v.size());
}