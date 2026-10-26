#include <bits/stdc++.h>

using namespace std;

/* Lower Bound: Finds the first index `i` such that v[i] >= target.
   If no such element exists, it returns `n`. */
   
// TC - O(log n), SC - O(1)
int lower_bound(vector<int>& v, int n, int target) {
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