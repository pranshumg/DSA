#include <bits/stdc++.h>

using namespace std;

/* next greater element 2 */
// https://leetcode.com/problems/next-greater-element-ii/

// TC - O(n), SC - O(n)
vector<int> next_greater_elements(vector<int>& v) {
  vector<int> nge(int(v.size()));
  stack<int> sk;
  for (int i = 2 * (int(v.size())) - 1; i >= 0; i--) {
    while (!sk.empty() && sk.top() <= v[i % int(v.size())]) {
      sk.pop();
    }
    if (i < int(v.size())) {
      nge[i] = !sk.empty() ? sk.top() : -1;
    }
    sk.push(v[i % int(v.size())]);
  }
  return nge;
}