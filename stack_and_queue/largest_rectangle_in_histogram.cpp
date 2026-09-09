#include <bits/stdc++.h>

using namespace std;

/* largest rectangle in histogram */
// https://leetcode.com/problems/largest-rectangle-in-histogram/

vector<int> prev_smaller_elements(vector<int>& v) {
  vector<int> pse(int(v.size()));
  stack<int> sk;
  for (int i = 0; i < int(v.size()); i++) {
    while (!sk.empty() && v[sk.top()] >= v[i]) {
      sk.pop();
    }
    pse[i] = !sk.empty() ? sk.top() : -1;
    sk.push(i);
  }
  return pse;
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

// TC - O(n), SC - O(n)
int largest_rectangle_area(vector<int>& v) {
  vector<int> pse = prev_smaller_elements(v);
  vector<int> nse = next_smaller_elements(v);
  int ans = 0;
  for (int i = 0; i < int(v.size()); i++) {
    ans = max(ans, (nse[i] - pse[i] - 1) * v[i]);
  }
  return ans;
} 