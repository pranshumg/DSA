#include <bits/stdc++.h>

using namespace std;

/* Four sum */
// https://leetcode.com/problems/4sum/

// Brute 
// TC - O(n * n * n * n), SC - O(m) where m is the no. of unique quadruplets
vector<vector<int>> four_sum(vector<int>& v, int n, int target) {
  set<vector<int>> st;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          // Note: This addition might overflow 'int' if numbers are large
          if (int64_t(v[i] + v[j] + v[k] + v[l]) == target) {
            vector<int> tmp = {v[i], v[j], v[k], v[l]};
            sort(tmp.begin(), tmp.end());
            st.insert(tmp);
          }
        }
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Better 
// TC - O(n * n * n), SC - O(n + m) where m is the no. of unique quadruplets
vector<vector<int>> four_sum(vector<int>& v, int n, int target) {
  set<vector<int>> st;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      set<int> hashset;
      for (int k = j + 1; k < n; k++) {
        int64_t cur = int64_t(v[i] + v[j] + v[k]);
        int64_t fourth = target - cur;
        if (hashset.find(fourth) != hashset.end()) {
          vector<int> tmp = {v[i], v[j], v[k], int(fourth)};
          sort(tmp.begin(), tmp.end());
          st.insert(tmp);
        }
        hashset.insert(v[k]);
      }
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Optimal 
// TC - O(n * n * n), SC - O(m)
vector<vector<int>> four_sum(vector<int>& v, int n, int target) {
  vector<vector<int>> ans;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (i > 0 && v[i] == v[i - 1]) {
      continue;
    }
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1 && v[j] == v[j - 1]) {
        continue;
      }
      int k = j + 1, l = n - 1;
      while (k < l) {
        int64_t sum = v[i];
        sum += v[j];
        sum += v[k];
        sum += v[l];
        if (sum < target) {
          k++;
        } else if (sum > target) {
          l--;
        } else {
          ans.emplace_back(v[i], v[j], v[k], v[l]);
          k++, l--;
          while (k < l && v[k] == v[k - 1]) {
            k++;
          }
          while (k < l && v[l] == v[l + 1]) {
            l--;
          }
        }
      }
    }
  }
  return ans;
}