#include <bits/stdc++.h>

using namespace std;

/* submask */

// TC - O(n*3^n), SC - O(n)
void submask(int n) {
  auto binary = [&](int mask) -> string {
    string s = "";
    for (int i = 0; i < n; i++) {
      s += (mask >> i) & 1 ? '1' : '0';
    }
    reverse(s.begin(), s.end());
    return s;
  };
  for (int mask = 0; mask < (1 << n); mask++) {
    cout << "mask: " << binary(mask) << '\n';
    for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
      cout << " -> submask: " << binary(submask) << '\n';
    }
    cout << " -> submask: " << string(n, '0') << '\n' << '\n';
  }
}