#include <bits/stdc++.h>

using namespace std;

/* Union of two sorted arrays */

// Brute
// TC - O((n + m)log(n + m)), SC - O(n + m)
vector<int> Union(vector<int>& v1, vector<int>& v2) {
    set<int> st;
    int n = int(v1.size()), m = int(v2.size());
    for (int i = 0; i < n; i++) {
        st.insert(v1[i]);
    }
    for (int i = 0; i < m; i++) {
        st.insert(v2[i]);
    }
    vector<int> ans(st.begin(), st.end());
    return ans;
}

// Optimal
// TC - O(n + m), SC - O(1)
vector<int> Union(vector<int>& v1, vector<int>& v2) {
    vector<int> ans;
    int n = int(v1.size()), m = int(v2.size()), i = 0, j = 0;
    while (i < n && j < m) {
        if (v1[i] <= v2[j]) {
            if (ans.empty() || ans.back() != v1[i]) {
                ans.push_back(v1[i++]);
            }
        } else {
            if (ans.empty() || ans.back() != v2[j]) {
                ans.push_back(v2[j++]);
            }
        }
    }
    while (i < n) {
        if (ans.empty() || ans.back() != v1[i]) {
            ans.push_back(v1[i++]);
        }
    }
    while (j < m) {
        if (ans.empty() || ans.back() != v2[j]) {
            ans.push_back(v2[j++]);
        }
    }
    return ans;
}