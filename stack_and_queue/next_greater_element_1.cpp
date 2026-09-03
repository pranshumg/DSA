#include <bits/stdc++.h>

using namespace std;

/* next greater element 1 */
// https://leetcode.com/problems/next-greater-element-i/

// TC - O(n), SC - O(n)
vector<int> next_greater_elements(vector<int>& v1, vector<int>& v2) { 
  vector<int> nge(int(v2.size()));
  stack<int> sk;
  for (int i = int(v2.size()) - 1; i >= 0; i--) {
    while (!sk.empty() && sk.top() <= v2[i]) {
      sk.pop();
    }
    nge[i] = (!sk.empty() ? sk.top() : -1);
    sk.push(v2[i]);
  }
  return nge;
}