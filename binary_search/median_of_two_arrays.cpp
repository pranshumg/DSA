#include <bits/stdc++.h>

using namespace std;

/* Median of two sorted arrays */
// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Merge and Store
// TC - O(n + m), SC - O(n + m) 
double median(vector<int>& v1, int m, vector<int>& v2, int n) {
    vector<int> res;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (v1[i] < v2[j]) {
            res.push_back(v1[i++]);
        } else {
            res.push_back(v2[j++]);
        }
    }
    while (i < m) res.push_back(v1[i++]);
    while (j < n) res.push_back(v2[j++]);
    if ((n + m) & 1) return res[(n + m) / 2];
    return (res[(n + m) / 2] + res[(n + m) / 2 - 1]) / double(2);
}

// Optimized Space (Pointer Tracking)
// TC - O(n + m), SC - O(1)
double median(vector<int>& v1, int n, vector<int>& v2, int m) {
    int cnt = 0;
    int idx1 = (n + m) / 2, idx2 = (n + m) / 2 - 1;
    int el1 = -1, el2 = -1;
    int i = 0, j = 0;
    while (i < n && j < m) {
        int val;
        if (v1[i] < v2[j]) {
            val = v1[i++];
        } else {
            val = v2[j++];
        }
        if (cnt == idx2) el2 = val;
        if (cnt == idx1) el1 = val;
        cnt++;
    }
    while (i < n) {
        if (cnt == idx2) el2 = v1[i];
        if (cnt == idx1) el1 = v1[i];
        i++; cnt++;
    }
    while (j < m) {
        if (cnt == idx2) el2 = v2[j];
        if (cnt == idx1) el1 = v2[j];
        j++; cnt++;
    }
    if ((n + m) & 1) return el1;
    return (el1 + el2) / double(2);
}

// Binary search
// TC - O(log(min(n, m))), SC - O(1)
double median(vector<int>& v1, int m, vector<int>& v2, int n) {
    if (m > n) return median(v2, n, v1, m);
    int left = (m + n + 1) / 2;
    int low = 0, high = m;
    while (low <= high) {
        int mid1 = low + (high - low) / 2;
        int mid2 = left - mid1;
        int l1 = (mid1 == 0) ? INT_MIN : v1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : v2[mid2 - 1];
        int r1 = (mid1 == m) ? INT_MAX : v1[mid1];
        int r2 = (mid2 == n) ? INT_MAX : v2[mid2];
        if (l1 <= r2 && l2 <= r1) {
            if ((n + m) & 1) return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return 0.0;
}