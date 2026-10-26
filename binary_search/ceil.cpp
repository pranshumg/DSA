#include <bits/stdc++.h>

using namespace std;

/* Ceil: Finds the smallest index `i` such that v[i] >= target. */

// TC - O(log n), SC - O(1)
int ceil(vector<int>& v, int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}