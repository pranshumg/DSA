#include <bits/stdc++.h>

using namespace std;

/* Search in a 2D matrix 1 */
// https://leetcode.com/problems/search-a-2d-matrix/

// Brute Force
// TC - O(n * m), SC - O(1)
bool search(vector<vector<int>>& v, int n, int m, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

// Row-wise binary search
// TC - O(n + log m), SC - O(1)
bool search(vector<vector<int>>& v, int n, int m, int target) {
    for (int i = 0; i < n; i++) {
        if (v[i][0] <= target && target <= v[i][m - 1]) {
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (v[i][mid] == target) {
                    return true;
                } else if (v[i][mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            break;
        }
    }
    return false;
}

// Flattened binary search
// TC - O(log(n * m)), SC - O(1)
bool search(vector<vector<int>>& v, int n, int m, int target) {
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if (v[row][col] == target) {
            return true;
        } else if (v[row][col] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}