#include <bits/stdc++.h>

using namespace std;

/* Spiral Traversal */
// https://leetcode.com/problems/spiral-matrix/

// TC - O(n * m), SC - O(n * m) (for storing the result)
vector<int> spiral(vector<vector<int>>& v, int n, int m) {
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> ans;
    while (top <= bottom && left <= right) {
        // 1. Traverse Left -> Right
        for (int i = left; i <= right; i++) {
            ans.push_back(v[top][i]);
        }
        top++;
        // 2. Traverse Top -> Bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(v[i][right]);
        }
        right--;
        // 3. Traverse Right -> Left
        // Check if top is still valid to avoid duplicate row traversal
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(v[bottom][i]);
            }
            bottom--;
        }
        // 4. Traverse Bottom -> Top
        // Check if left is still valid to avoid duplicate column traversal
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(v[i][left]);
            }
            left++;
        }
    }
    return ans;
}