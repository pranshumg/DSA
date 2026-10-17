#include <bits/stdc++.h>

using namespace std;

/* sliding window maximum */
// https://leetcode.com/problems/sliding-window-maximum/

// TC - O(n * k), SC - O(1)
vector<int> max_sliding_window(vector<int>& v, int k) {
  vector<int> res;
  for (int i = 0; i <= int(v.size()) - k; i++) {
    int mx = INT32_MIN;
    for (int j = i; j < i + k; j++) {
      mx = max(mx, v[j]);
    }
    res.push_back(mx);
  }
  return res;
}

// TC - O(n log k), SC - O(k)
vector<int> max_sliding_window(vector<int>& v, int k) {
  vector<int> res;
  multiset<int> mst;
  for (int l = 0, r = 0; r < int(v.size()); r++) {
    mst.insert(v[r]);
    while (r - l + 1 > k) {
      mst.erase(mst.find(v[l++]));
    }
    if (r - l + 1 == k) {
      res.push_back(*mst.rbegin());
    }
  }
  return res;
}

// TC - O(n), SC - O(k)
vector<int> max_sliding_window(vector<int>& v, int k) {
  vector<int> res;
  deque<int> dq;
  for (int i = 0; i < int(v.size()); i++) {
    if (!dq.empty() && dq.front() <= i - k) {
      dq.pop_front();
    }
    while (!dq.empty() && v[dq.back()] <= v[i]) {
      dq.pop_back();
    }
    dq.push_back(i);
    if (i >= k - 1) {
      res.push_back(v[dq.front()]);
    }
  }
  return res;
}