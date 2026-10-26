#include <bits/stdc++.h>

using namespace std;

/* Rotate matrix/image by 90 degrees */
// https://leetcode.com/problems/rotate-image/

// Brute (Works for Rectangular Matrices too)
// TC - O(n * m), SC - O(n * m)
vector<vector<int>> rotate(vector<vector<int>>& v, int n, int m) {
    vector<vector<int>> ans(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Formula for 90 degree clockwise 
            ans[j][(n - 1) - i] = v[i][j];
        }
    }
    return ans;
}

// Optimal Approach (In-Place)
// NOTE: This ONLY works for Square Matrices (n == m)
// TC - O(n * n), SC - O(1)
void rotate(vector<vector<int>>& v, int n) {
    // Step 1: Transpose the matrix (Swap v[i][j] with v[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(v[i][j], v[j][i]);
        }
    }
    // Step 2: Reverse every row
    for (int i = 0; i < n; i++) {
        reverse(v[i].begin(), v[i].end());
    }
}