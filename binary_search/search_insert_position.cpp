#include <bits/stdc++.h>

using namespace std;

/* Search Insert Position: Finds the index where 'target' is or should be. */
// https://leetcode.com/problems/search-insert-position/

// TC - O(log n), SC - O(1)
int search_insert_position(vector<int>& v, int n, int target) {
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