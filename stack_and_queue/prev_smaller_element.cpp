#include <bits/stdc++.h>

using namespace std;

/* previous smaller element */

// TC - O(n), SC - O(n)
vector<int> prev_smaller_elements(vector<int>& v) {
  vector<int> pse(int(v.size()));
  stack<int> sk;
  for (int i = 0; i < int(v.size()); i++) {
    while (!sk.empty() && sk.top() >= v[i]) {
      sk.pop();
    }
    pse[i] = !sk.empty() ? sk.top() : -1;
    sk.push(v[i]);
  }
  return pse;
}