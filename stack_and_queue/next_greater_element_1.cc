#include <bits/stdc++.h>

using namespace std;

/* next greater element 1 */
// https://leetcode.com/problems/next-greater-element-i/

// TC - O(n), SC - O(n)
vector<int> next_greater_elements(vector<int>& v) { 
  vector<int> nge(int(v.size()));
  stack<int> sk;
  for (int i = int(v.size()) - 1; i >= 0; i--) {
    while (!sk.empty() && sk.top() <= v[i]) {
      sk.pop();
    }
    nge[i] = (!sk.empty() ? sk.top() : -1);
    sk.push(v[i]);
  }
  return nge;
}