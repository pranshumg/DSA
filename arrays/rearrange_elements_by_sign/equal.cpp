#include <bits/stdc++.h>

using namespace std;

/* Rearrange equal positive and negative elements by sign */
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Brute 
// TC - O(n), SC - O(n)
vector<int> rearrange_array(vector<int>& v, int n) {
  vector<int> pos, neg;
  for (int i = 0; i < n; i++) {
    if (v[i] > 0) {
      pos.push_back(v[i]);
    } else {
      neg.push_back(v[i]);
    }
  }  
  vector<int> res(n);
  for (int i = 0; i < n / 2; i++) {
    res[2 * i] = pos[i];
    res[2 * i + 1] = neg[i];
  }   
  return res;
}

// Optimal Approach (Two Pointers)
// TC - O(n), SC - O(n)
// Note: We still use O(n) space for the result, but we avoid the extra pass and vectors.
vector<int> rearrange_array(vector<int>& v, int n) {
  vector<int> res(n);
  int pos = 0, neg = 1; 
  for (int i = 0; i < n; i++) {
    if (v[i] > 0) {
      res[pos] = v[i], pos += 2;
    } else {
      res[neg] = v[i], neg += 2;
    }
  }
  return res;
}