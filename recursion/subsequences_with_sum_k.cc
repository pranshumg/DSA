#include <bits/stdc++.h>

using namespace std;

/* Subsequences with sum k */

// Generate all subsequences
// TC - O(2^n * n), SC - O(n)
void subsequences(int idx, int n, int64_t sum, int64_t k, vector<int>& v, vector<int>& res) {
  if (idx >= n) {
    if (sum == k) {
      for (auto& a : res) {
        cout << a << ' ';
      }
      cout << '\n';
    }
    return;
  }
  res.push_back(v[idx]);
  subsequences(idx + 1, n, sum + v[idx], k, v, res);
  res.pop_back();
  subsequences(idx + 1, n, sum, k, v, res); 
}

// Generate one subsequence
// TC - O(2^n * n), SC - O(n)
bool check_subsequence(int idx, int n, int64_t sum, int64_t k, vector<int>& v, vector<int>& res) {
  if (idx >= n) {
    if (sum == k) {
      for (auto& a : res) {
        cout << a << ' ';
      }
      cout << '\n';
      return true;
    }
    return false;
  }
  res.push_back(v[idx]);
  if (check_subsequence(idx + 1, n, sum + v[idx], k, v, res)) return true;
  res.pop_back();
  if (check_subsequence(idx + 1, n, sum, k, v, res)) return true;
  return false;
}

// Count subsequences
// TC - O(2^n), SC - O(n)
int count_subsequences(int idx, int n, int64_t sum, int64_t k, vector<int>& v) {
  if (idx >= n) return sum == k;
  int left = count_subsequences(idx + 1, n, sum + v[idx], k, v);
  int right = count_subsequences(idx + 1, n, sum, k, v);
  return left + right;
}