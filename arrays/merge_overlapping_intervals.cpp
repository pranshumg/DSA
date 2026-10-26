#include <bits/stdc++.h>

using namespace std;

/* Merge overlapping intervals */
// https://leetcode.com/problems/merge-intervals/

// Brute 
// TC - O(n log n), SC - O(n)
vector<vector<int>> merge(vector<vector<int>>& v, int n) {
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        int f = v[i][0], s = v[i][1];
        // Skip if this interval is already merged into the last one in ans
        if (!ans.empty() && s <= ans.back()[1]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (v[j][0] <= s) {
                s = max(s, v[j][1]);
            } else {
                break;
            }
        }
        ans.emplace_back(f, s);
    }
    return ans;
}

// Optimal 
// TC - O(n log n), SC - O(n)
vector<vector<int>> merge(vector<vector<int>>& v, int n) {
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        // If ans is empty or current interval does not overlap with the last one
        if (ans.empty() || v[i][0] > ans.back()[1]) {
            ans.push_back(v[i]);
        } 
        // Overlap detected: merge by updating the end time
        else {
            ans.back()[1] = max(ans.back()[1], v[i][1]);
        }
    }
    return ans;
}