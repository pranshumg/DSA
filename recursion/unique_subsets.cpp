#include <bits/stdc++.h>

using namespace std;

/* Unique subsets */
// https://leetcode.com/problems/subsets-ii/

void find_subset(int idx, int n, vector<int>& v, vector<int>& tmp, set<vector<int>>& st) {
    if (idx >= n) {
        st.insert(tmp);
        return;
    }
    tmp.push_back(v[idx]);
    find_subset(idx + 1, n, v, tmp, st);
    tmp.pop_back();
    find_subset(idx + 1, n, v, tmp, st);
}

// Hashset
// TC - O(2^n * n * n), SC - O(2^n * n) 
vector<vector<int>> combination_sum_2(vector<int>& v, int n) {
    sort(v.begin(), v.end());
    vector<int> tmp;
    set<vector<int>> st;
    find_subset(0, n, v, tmp, st);
    vector<vector<int>> res(st.begin(), st.end()); 
    return res;
}

void find_subset(int idx, int n, vector<int>& v, vector<int>& tmp, vector<vector<int>>& res) {
    res.push_back(tmp);
    for (int i = idx; i < n; i++) {
        if (i > idx && v[i] == v[i - 1]) {
            continue;
        }
        tmp.push_back(v[i]);
        find_subset(i + 1, n, v, tmp, res);
        tmp.pop_back();
    }
}

// TC - O(2^n * n), SC - O(2^n * n)
vector<vector<int>> subsets(vector<int>& v, int n) {
    sort(v.begin(), v.end());
    vector<int> tmp;
    vector<vector<int>> res;
    find_subset(0, n, v, tmp, res);
    return res;
}