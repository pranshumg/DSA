#include <bits/stdc++.h>

using namespace std;

/* sum of subarray ranges */
// https://leetcode.com/problems/sum-of-subarray-ranges/

vector<int> next_greater_elements(vector<int>& v) {
  vector<int> nge(int(v.size()));
  stack<int> sk;
  for (int i = int(v.size()) - 1; i >= 0; i--) {
    while (!sk.empty() && v[sk.top()] <= v[i]) {
      sk.pop();
    }
    nge[i] = !sk.empty() ? sk.top() : int(v.size());
    sk.push(i);
  }
  return nge;
}

vector<int> next_smaller_elements(vector<int>& v) {
  vector<int> nse(int(v.size()));
  stack<int> sk;
  for (int i = int(v.size()) - 1; i >= 0; i--) {
    while (!sk.empty() && v[sk.top()] >= v[i]) {
      sk.pop();
    }
    nse[i] = !sk.empty() ? sk.top() : int(v.size());
    sk.push(i);
  }
  return nse;
}

vector<int> prev_greater_elements(vector<int>& v) {
  vector<int> pge(int(v.size()));
  stack<int> sk;
  for (int i = 0; i < int(v.size()); i++) {
    while (!sk.empty() && v[sk.top()] < v[i]) {
      sk.pop();
    }
    pge[i] = !sk.empty() ? sk.top() : -1;
    sk.push(i);
  }
  return pge;
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
int64_t sum_of_subarray_ranges(vector<int>& v) {
  vector<int> nge = next_greater_elements(v);
  vector<int> nse = next_smaller_elements(v);
  vector<int> pge = prev_greater_elements(v);
  vector<int> pse = prev_smaller_elements(v);
  int64_t ans = 0;
  for (int i = 0; i < int(v.size()); i++) {
    ans += (int64_t(v[i]) * (nge[i] - i) * (i - pge[i]));
    ans -= (int64_t(v[i]) * (nse[i] - i) * (i - pse[i]));
  }
  return ans;
}