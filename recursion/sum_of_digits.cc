#include <bits/stdc++.h>

using namespace std;

/* Sum of digits */

// TC - O(no. of digits), SC - O(no. of digits)
int sum_of_digits(int n) {
  if (n == 0) {
    return 0;
  }
  return n % 10 + sum_of_digits(n / 10);
}