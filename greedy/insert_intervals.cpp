#include <bits/stdc++.h>

using namespace std;

/* insert intervals */
// https://leetcode.com/problems/insert-interval/

// TC - O(n), SC - O(n)
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
  vector<vector<int>> res;
  int i = 0;
  while (i < int(intervals.size()) && intervals[i][1] < new_interval[0]) {
    res.push_back(intervals[i++]);
  }
  while (i < int(intervals.size()) && new_interval[1] >= intervals[i][0]) {
    new_interval[0] = min(new_interval[0], intervals[i][0]); 
    new_interval[1] = max(new_interval[1], intervals[i++][1]); 
  }
  res.push_back(new_interval);
  while (i < int(intervals.size())) {
    res.push_back(intervals[i++]);
  }
  return res;
}