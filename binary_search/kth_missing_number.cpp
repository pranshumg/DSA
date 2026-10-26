#include <bits/stdc++.h>

using namespace std;

/* Kth missing positive number */
// https://leetcode.com/problems/kth-missing-positive-number/

// TC - O(log n), SC - O(1)
int kth_missing(vector<int>& v, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] - mid - 1 < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + k;
}