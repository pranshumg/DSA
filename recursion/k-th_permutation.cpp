#include <bits/stdc++.h>

using namespace std;

/* K-th permutation sequence */
// https://leetcode.com/problems/permutation-sequence/

void solve(int idx, string& s, vector<string>& res) {
  if (idx == int(s.size())) {
    res.push_back(s);
    return;
  }
  for (int i = idx; i < int(s.size()); i++) {
    swap(s[idx], s[i]);
    solve(idx + 1, s, res);
    swap(s[idx], s[i]);
  }
}

// TC - O(n * n! * log(n!)), SC - O(n * n!)
string get_permutation(int n, int k) {
  vector<string> res;
  string s = "";
  for (int i = 1; i <= n; i++) {
    s += i + '0';
  }
  solve(0, s, res);
  sort(res.begin(), res.end());
  return res[k - 1];
}

// TC - O(n^2), SC - O(n)
string get_permutation(int n, int k) {
  int fact = 1;
  vector<int> nums;
  for (int i = 1; i < n; i++) {
    fact *= i;
    nums.push_back(i);
  }
  nums.push_back(n);
  string ans = "";
  k--;
  while (true) {
    ans += to_string(nums[k / fact]);
    nums.erase(nums.begin() + k / fact);
    if (nums.empty()) {
      break;
    }
    k %= fact;
    fact /= int(nums.size());
  }
  return ans;
}