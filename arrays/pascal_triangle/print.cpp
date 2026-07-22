#include <bits/stdc++.h>

using namespace std;

/* Print Pascal Triangle */
// https://leetcode.com/problems/pascals-triangle/

// Helper for Brute Force
// TC - O(r), SC - O(1)
int64_t nCr(int n, int r) {
  int64_t res = 1;
  for (int i = 0; i < r; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

// Brute Force approach to generate the whole triangle
// TC - O(n * n * n), SC - O(1)
vector<vector<int>> generate(int n) {
  vector<vector<int>> ans;
  for (int r = 0; r < n; r++) {
    vector<int> tmp;
    for (int c = 0; c <= r; c++) {
      tmp.push_back(int(nCr(r, c)));
    }
    ans.push_back(tmp);
  }
  return ans;
}

// Optimal helper to generate a single row
// TC - O(r), SC - O(1)
vector<int> generate_row(int r) {
  vector<int> row;
  int64_t ans = 1;
  row.push_back(1);
  for (int c = 1; c < r; c++) {
    ans *= (r - c);
    ans /= c;
    row.push_back(int(ans));
  }
  return row;
}

// Optimal approach to generate the whole triangle
// TC - O(n²), SC - O(1) 
vector<vector<int>> generate(int n) {
  vector<vector<int>> ans;
  for (int r = 1; r <= n; r++) {
    ans.push_back(generate_row(r));
  }
  return ans;
}