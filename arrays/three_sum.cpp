#include <bits/stdc++.h>

using namespace std;

/* Three sum */
// https://leetcode.com/problems/3sum/

// Brute 
// TC - O(n * n * n), SC - O(m) where m is the no. of unique triplets
vector<vector<int>> three_sum(vector<int>& v, int n) {
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (v[i] + v[j] + v[k] == 0) {
                    vector<int> tmp = {v[i], v[j], v[k]};
                    sort(tmp.begin(), tmp.end());
                    st.insert(tmp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Better
// TC - O(n * n), SC - O(n + m) where m is the no. of unique triplets
vector<vector<int>> three_sum(vector<int>& v, int n) {
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            if (hashset.find(-(v[i] + v[j])) != hashset.end()) {
                vector<int> tmp = {v[i], v[j], -(v[i] + v[j])};
                sort(tmp.begin(), tmp.end());
                st.insert(tmp);
            }
            hashset.insert(v[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Optimal
// TC - O(n * n), SC - O(m)
vector<vector<int>> three_sum(vector<int>& v, int n) {
    vector<vector<int>> ans;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) {
            continue;
        }
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = v[i] + v[j] + v[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.emplace_back(v[i], v[j], v[k]);
                j++, k--;
                while (j < k && v[j] == v[j - 1]) {
                    j++;
                }
                while (j < k && v[k] == v[k + 1]) {
                    k--;
                }
            }
        }
    }
    return ans;
}