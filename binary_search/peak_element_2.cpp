#include <bits/stdc++.h>

using namespace std;

/* Peak element 2 */
// https://leetcode.com/problems/find-a-peak-element-ii/

// TC - O(n log m), SC - O(1)
pair<int, int> peak(vector<vector<int>>& v, int n, int m) {
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int mx = v[0][mid], row = 0;
        for (int i = 0; i < n; ++i) {
            if (mx < v[i][mid]) {
                mx = v[i][mid];
                row = i;
            }
        }
        int left = (mid > 0 ? v[row][mid - 1] : -1);
        int right = (mid < m - 1 ? v[row][mid + 1] : -1);
        if (mx > left && mx > right) {
            return {row, mid};
        } else if (mx < left) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return {-1, -1};
}