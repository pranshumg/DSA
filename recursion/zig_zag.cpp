#include <bits/stdc++.h>

using namespace std;

/* Prints n to 1 to n */

// TC - O(n), SC - O(n)
void zig_zag(int n) {
  if (n == 1) {
    cout << 1 << '\n';
    return;
  }
  cout << n << '\n';
  zig_zag(n - 1);
  cout << n << '\n';
}