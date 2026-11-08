#include <bits/stdc++.h>

using namespace std;

/* merge intervals */
// https://leetcode.com/problems/merge-intervals/

// TC - O(n log n), SC - O(n)
vector<vector<int>> merge(vector<vector<int>>& v) {
    if (v.empty()) {
        return {};
    }
    sort(v.begin(), v.end());
    vector<vector<int>> res;
    res.push_back(v[0]);
    for (int i = 1; i < int(v.size()); i++) {
        if (res.back()[1] >= v[i][0]) {
            res.back()[1] = max(res.back()[1], v[i][1]);
        } else {
            res.push_back(v[i]);
        }
    }
    return res;
}