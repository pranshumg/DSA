#include <bits/stdc++.h>

using namespace std;

const int md = int(1e9) + 7;

/* sum of subarray minimums */
// https://leetcode.com/problems/sum-of-subarray-minimums/

vector<int> next_smaller_elements(vector<int>& v) {
  vector<int> nse(int(v.size()));
  stack<int> sk;
  for (int i = int(v.size()) - 1; i >= 0; i--) {
    while (!sk.empty() && v[sk.top()] >= v[i]) {
      sk.pop();
    }
    nse[i] = !sk.empty() ? sk.top() : -1;
    sk.push(i);
  }
  return nse;
}

vector<int> prev_smaller_elements(vector<int>& v) {
  vector<int> pse(int(v.size()));
  stack<int> sk;
  for (int i = 0; i < int(v.size()); i++) {
    while (!sk.empty() && v[sk.top()] > v[i]) {
      sk.pop();
    }
    pse[i] = !sk.empty() ? sk.top() : -1;
    sk.push(i);
  }
  return pse;
}

// TC - O(n), SC - O(n)
int sum_subarray_mins(vector<int>& v) {
  vector<int> nse = next_smaller_elements(v);
  vector<int> pse = prev_smaller_elements(v);
  int64_t ans = 0;
  for (int i = 0; i < int(v.size()); i++) {
    ans = (ans + int64_t(v[i]) * (nse[i] - i) * (i - pse[i])) % md;
  }
  return ans;
}