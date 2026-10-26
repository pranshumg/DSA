#include <bits/stdc++.h>

using namespace std;

/* Longest consecutive sequence */
// http://leetcode.com/problems/longest-consecutive-sequence/

// Helper function for Brute 
bool linear_search(vector<int>& v, int k) {
    for (int i = 0; i < int(v.size()); i++) {
        if (v[i] == k) {
            return true;
        }
    }
    return false;
}

// Brute 
// TC - O(n * n), SC - O(1)
int longest_sequence(vector<int>& v, int n) {
    if (n == 0) {
        return 0;
    }
    int longest = 1;
    for (int i = 0; i < n; i++) {
        int cnt = 1, el = v[i];
        while (linear_search(v, el + 1)) {
            el++;
            cnt++;
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// Better Approach (Sorting)
// TC - O(n log n), SC - O(1)
int longest_sequence(vector<int>& v, int n) {
    if (n == 0) {
        return 0;
    }
    sort(v.begin(), v.end());
    int longest = 1, cnt = 0, last_smaller = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (v[i] - 1 == last_smaller) { 
            cnt++, last_smaller = v[i];
        } else if (v[i] != last_smaller) {
            cnt = 1, last_smaller = v[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// Optimal Approach (Hashset)
// TC - O(n), SC - O(n)
int longest_sequence(vector<int>& v, int n) {
    if (n == 0) {
        return 0;
    }
    int longest = 1;
    set<int> st;
    for (auto& a : v) {
        st.insert(a);
    }
    for (auto& a : st) {
        if (st.find(a - 1) == st.end()) {
            int el = a, cnt = 1;
            while (st.find(el + 1) != st.end()) {
                el++;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}