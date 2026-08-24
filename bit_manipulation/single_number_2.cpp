#include <bits/stdc++.h>

using namespace std;

/* single number 2 */
// https://leetcode.com/problems/single-number-ii/

// TC - O(n log n), SC - O(n)
int single_number(vector<int>& v) {
  map<int, int> mp;
  for (int i : v) {
    mp[i]++;
  }
  for (auto& [el, cnt] : mp) {
    if (cnt == 1) {
      return el;
    }
  }
  return -1;
}

// TC - O(n log n), SC - O(1)
int single_number(vector<int>& v) {
  sort(v.begin(), v.end());
  for (int i = 0; i < int(v.size()) - 1; i += 3) {
    if (v[i] != v[i + 1]) {
      return v[i];
    }
  }
  return v.back();
}

// TC - O(n), SC - O(1)
int single_number(vector<int>& v) {
  int ans = 0;
  for (int i = 0; i < 32; i++) {
    int cnt = 0;
    for (int j = 0; j < int(v.size()); j++) {
      cnt += (v[j] >> i) & 1;
    }
    if (cnt % 3 != 0) {
      ans |= (unsigned(1) << i);
    }
  }
  return ans;
} 

// TC - O(n), SC - O(1)
int single_number(vector<int>& v) {
  int ones = 0, twos = 0;
  for (int i : v) {
    ones = (ones ^ i) & ~twos;
    twos = (twos ^ i) & ~ones;
  }
  return ones;
}