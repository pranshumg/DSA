#include <bits/stdc++.h>

using namespace std;

/* Combination sum 2 */
// https://leetcode.com/problems/combination-sum-ii/

void find_combination(int idx, int n, int target, vector<int>& v, vector<int>& tmp, set<vector<int>>& st) {
    if (target == 0) {
        st.insert(tmp);
        return;
    }
    if (idx >= n || target < 0) return;
    tmp.push_back(v[idx]);
    find_combination(idx + 1, n, target - v[idx], v, tmp, st);
    tmp.pop_back();
    find_combination(idx + 1, n, target, v, tmp, st);
}

// Hashset
// TC - O(2^n * n * log m), SC - O(2^n * n) where n = no. of candidates, m = no. of stored combinations
vector<vector<int>> combination_sum_2(vector<int>& v, int target) {
    sort(v.begin(), v.end());
    vector<int> tmp;
    set<vector<int>> st;
    find_combination(0, int(v.size()), target, v, tmp, st);
    vector<vector<int>> res(st.begin(), st.end()); 
    return res;
}

void find_combination(int idx, int n, int target, vector<int>& v, vector<int>& tmp, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(tmp);
        return;
    }
    for (int i = idx; i < n && target >= v[i]; i++) {
        if (i > idx && v[i] == v[i - 1]) {
            continue;
        }
        tmp.push_back(v[i]);
        find_combination(i + 1, n, target - v[i], v, tmp, res);
        tmp.pop_back();
    }
}

// Optimal
// TC - O(2^n * n), SC - O(2^n * n) where n = no. of candidates
vector<vector<int>> combination_sum_2(vector<int>& v, int target) {
    sort(v.begin(), v.end());
    vector<int> tmp;
    vector<vector<int>> res; 
    find_combination(0, int(v.size()), target, v, tmp, res);
    return res;
}