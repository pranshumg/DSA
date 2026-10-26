#include <bits/stdc++.h>

using namespace std;

/* Single element in sorted array */
// https://leetcode.com/problems/single-element-in-a-sorted-array/

// TC - O(log n), SC - O(1)
int single(vector<int>& v, int n) {
    if (n == 1) return v[0];
    if (v[0] != v[1]) return v[0];
    if (v[n - 1] != v[n - 2]) return v[n - 1];
    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid - 1] != v[mid] && v[mid] != v[mid + 1]) {
            return v[mid];
        }
        if ((mid & 1 && v[mid] == v[mid - 1]) || (mid % 2 == 0 && v[mid] == v[mid + 1])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}