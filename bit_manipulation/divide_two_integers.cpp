#include <bits/stdc++.h>

using namespace std;

/* divide two integers */
// https://leetcode.com/problems/divide-two-integers/

// TC - O(log n)^2, SC - O(1)
int divide(int dividend, int divisor) { 
  if (dividend == divisor) {
    return 1;
  }
  bool sign = true;
  if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
    sign = false;
  }
  int64_t n = abs(int64_t(dividend)), d = abs(int64_t(divisor));
  int64_t ans = 0;
  while (n >= d) {
    int cnt = 0;
    while (n >= (int64_t(d) << (cnt + 1))) {
      cnt++;
    }
    ans += int64_t(1) << cnt;
    n -= int64_t(d) << cnt;
  }
  if (!sign) {
    ans = -ans;
    return ans < INT_MIN ? INT_MIN : ans;
  }
  return ans > INT_MAX ? INT_MAX : ans;
}