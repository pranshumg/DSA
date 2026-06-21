#include <bits/stdc++.h>

using namespace std;

/* Permutations */
// https://leetcode.com/problems/permutations/

void find_permutation(vector<bool>& vis, vector<int>& v, vector<int>& tmp, vector<vector<int>>& res) {
    if (int(tmp.size()) == int(v.size())) {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < int(v.size()); i++) {
        if (!vis[i]) {
            tmp.push_back(v[i]);
            vis[i] = true;
            find_permutation(vis, v, tmp, res);
            tmp.pop_back();
            vis[i] = false;
        }
    }
}

// TC - O(n! * n), SC - O(n)
vector<vector<int>> permute(vector<int>& v) {
    vector<int> tmp;
    vector<vector<int>> res;
    vector<bool> vis(int(v.size()), false);
    find_permutation(vis, v, tmp, res);
    return res;
}

void find_permutation(int idx, vector<int>& v, vector<vector<int>>& res) {
    if (idx == int(v.size())) {
        res.push_back(v);
        return;
    }
    for (int i = idx; i < int(v.size()); i++) {
        swap(v[idx], v[i]);
        find_permutation(idx + 1, v, res);
        swap(v[idx], v[i]);
    }
}

// TC - O(n! * n), SC - O(n)    
vector<vector<int>> permute(vector<int>& v) {
    vector<vector<int>> res;
    find_permutation(0, v, res);
    return res;
}