#include <bits/stdc++.h>

using namespace std;

/* Row with maximum no. of ones */

// Brute Force
// TC - O(n * m), SC - O(1) 
int row(vector<vector<int>>& v, int n, int m) {
    int mx = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += v[i][j];
        }
        if (cnt > mx) {
            mx = cnt;
            idx = i;
        }
    }
    return idx;
}

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

// Binary Search 
// TC - O(n log m), SC - O(1)
int row2(vector<vector<int>>& v, int n, int m) {
    int mx = 0, idx = -1;
    for (int i = 0; i < n; i++) {
        int cnt = m - lower_bound(v[i], m, 1);
        if (cnt > mx) {
            mx = cnt;
            idx = i;
        }
    }
    return idx;
}