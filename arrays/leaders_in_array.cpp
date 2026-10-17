#include <bits/stdc++.h>

using namespace std;

/* Leaders in an array */

// Brute 
// TC - O(n * n), SC - O(n) 
vector<int> leaders(vector<int>& v, int n) {
  vector<int> res;
  for (int i = 0; i < n; i++) {
    bool is_leader = true;    
    for (int j = i + 1; j < n; j++) {
      if (v[j] > v[i]) {
        is_leader = false;
        break;
      }
    }
    if (is_leader) {
      res.push_back(v[i]);
    }
  }
  return res;
}

// Optimal Approach
// TC - O(n), SC - O(n) 
vector<int> leaders(vector<int>& v, int n) {
  vector<int> res;
  int mx = INT_MIN;
  for (int i = n - 1; i >= 0; i--) {
    if (v[i] > mx) {
      res.push_back(v[i]);
      mx = v[i];
    }
  }
  reverse(res.begin(), res.end());
  return res;
}