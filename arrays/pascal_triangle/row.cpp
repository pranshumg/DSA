#include <bits/stdc++.h>

using namespace std;

/* Print any nth row of Pascal Triangle */

int64_t nCr(int n, int r) {
  int64_t res = 1;
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

// Brute Force approach using nCr function
// TC - O(r * r), SC - O(1)
void print_row(int r) {
  for (int c = 1; c <= r; c++) {
    cout << nCr(r - 1, c - 1) << ' ';
  }
  cout << '\n';
}

// Optimal approach using the property: Next Term = Current Term * (row - col) / col
// TC - O(r), SC - O(1)
void print_row(int r) {
  int64_t ans = 1;
  cout << ans << ' '; // The first element is always 1
  for (int i = 1; i < r; i++) {
    ans *= (r - i);
    ans /= i;
    cout << ans << ' ';
  }
  cout << '\n';
}