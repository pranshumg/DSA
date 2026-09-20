#include <bits/stdc++.h>

using namespace std;

/* maximal rectangle */
// https://leetcode.com/problems/maximal-rectangle/

// TC - O(rows * cols^2), SC - O(rows * cols)
int maximal_rectangle(vector<vector<char>>& v) {
  int rows = int(v.size()), cols = int(v[0].size());
  vector<vector<int>> next_zero(rows, vector<int>(cols)), top_zero(rows, vector<int>(cols)), bottom_zero(rows, vector<int>(cols));
  for (int i = 0; i < rows; i++) {
    stack<int> sk;
    for (int j = cols - 1; j >= 0; j--) {
      while (!sk.empty() && v[i][sk.top()] == '1') {
        sk.pop();
      }
      next_zero[i][j] = !sk.empty() ? sk.top() : cols;
      sk.push(j);
    }
  }
  for (int j = 0; j < cols; j++) {
    stack<int> sk;
    for (int i = 0; i < rows; i++) {
      while (!sk.empty() && v[sk.top()][j] == '1') {
        sk.pop();
      }
      top_zero[i][j] = !sk.empty() ? sk.top() : -1;
      sk.push(i);
    }
    stack<int>().swap(sk);
    for (int i = rows - 1; i >= 0; i--) {
      while (!sk.empty() && v[sk.top()][j] == '1') {
        sk.pop();
      }
      bottom_zero[i][j] = !sk.empty() ? sk.top() : rows;
      sk.push(i);
    }
  }
  int ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (v[i][j] == '1') {
        int top = 0, bottom = rows;
        for (int k = j; k < next_zero[i][j]; k++) {
          top = max(top, top_zero[i][k]);
          bottom = min(bottom, bottom_zero[i][k]);
        }
        ans = max(ans, (next_zero[i][j] - j) * (bottom - top - 1));
      }
    }
  }
  return ans;
}