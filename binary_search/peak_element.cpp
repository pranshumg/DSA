#include <bits/stdc++.h>

using namespace std;

/* Peak element */
// https://leetcode.com/problems/find-peak-element/

// TC - O(log n), SC - O(1)
int peak(vector<int>& v, int n) {
    if (n == 1) return v[0];
    if (v[0] > v[1]) return v[0];
    if (v[n - 1] > v[n - 2]) return v[n - 1];
    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid - 1] < v[mid] && v[mid] > v[mid + 1]) {
            return v[mid];
        }
        if (v[mid - 1] < v[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}