#include <bits/stdc++.h>

using namespace std;

/* Search in rotated sorted array - 2 */
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// TC - O(log n) (average), SC - O(1)
bool search(vector<int>& v, int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) {
            return true;
        }
        if (v[low] == v[mid] && v[mid] == v[high]) {
            low++;
            high--;
            continue;
        }
        if (v[low] <= v[mid]) {
            if (v[low] <= target && target <= v[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (v[mid] <= target && target <= v[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}