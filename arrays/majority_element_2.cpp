#include <bits/stdc++.h>

using namespace std;

/* Majority element II */
// https://leetcode.com/problems/majority-element-ii/

// Brute 
// TC - O(n * n), SC - O(1)
vector<int> majority_element(vector<int>& v, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // Check if the element is already added to avoid duplicates
        if (int(ans.size()) == 0 || ans[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (v[i] == v[j]) {
                    cnt++;
                }
            }
            if (cnt > n / 3) {
                ans.push_back(v[i]);
            }
        }
        if (int(ans.size()) == 2) {
            break;
        }
    }
    return ans;
}

// Better 
// TC - O(n), SC - O(n)
vector<int> majority_element(vector<int>& v, int n) {
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[v[i]]++;
        // Add to answer only the first time it crosses the threshold
        if (mp[v[i]] == (n / 3) + 1) {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

// Moore's Voting algorithm (Optimal)
// TC - O(n), SC - O(1)
vector<int> majority_element(vector<int>& v, int n) {
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    // Pass 1: Find potential candidates
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && v[i] != el2) {
            cnt1 = 1, el1 = v[i];
        } else if (cnt2 == 0 && v[i] != el1) {
            cnt2 = 1, el2 = v[i];
        } else if (el1 == v[i]) {
            cnt1++;
        } else if (el2 == v[i]) {
            cnt2++;
        } else {
            cnt1--, cnt2--;
        }
    }
    // Pass 2: Verify candidates
    vector<int> ans;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (el1 == v[i]) {
            cnt1++;
        }
        if (el2 == v[i]) {
            cnt2++;
        }
    }
    if (cnt1 >= (n / 3) + 1) {
        ans.push_back(el1);
    }
    if (cnt2 >= (n / 3) + 1) {
        ans.push_back(el2);
    }
    return ans;
}