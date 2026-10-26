#include <bits/stdc++.h>

using namespace std;

/* Finds how many times a sorted array has been rotated */

// TC - O(log n), SC - O(1)
int times(vector<int>& v, int n) {
    int low = 0, high = n - 1;
    int mn = 1e9, idx = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[low] <= v[high]) {
            if (v[low] < mn) {
                mn = v[low];
                idx = low;
            }
            break; 
        }
        if (v[low] <= v[mid]) {
            if (v[low] < mn) {
                mn = v[low];
                idx = low;
            }
            low = mid + 1;
        } else {
            if (v[mid] < mn) {
                mn = v[mid];
                idx = mid;
            }
            high = mid - 1;
        }
    }
    return idx; 
}