#include <bits/stdc++.h>

using namespace std;

/* Combination sum 1 */
// https://leetcode.com/problems/combination-sum/

void find_combination(int idx, int n, int target, vector<int>& v, vector<int>& tmp, vector<vector<int>>& res) {
    if (target == 0) {
        res.push_back(tmp);
        return;
    }
    if (idx >= n || target < 0) return;
    tmp.push_back(v[idx]);
    find_combination(idx, n, target - v[idx], v, tmp, res);
    tmp.pop_back();
    find_combination(idx + 1, n, target, v, tmp, res);
}

// TC - O(2^t * k) due to exploring all combinations up to the target with copying each valid combination of average length k.
// SC - O(k * x) to store all valid combinations, where x is the number of combinations and k is their average length.
vector<vector<int>> combination_sum(vector<int>& v, int target) {
    vector<int> tmp;
    vector<vector<int>> res; 
    find_combination(0, int(v.size()), target, v, tmp, res);
    return res;
}