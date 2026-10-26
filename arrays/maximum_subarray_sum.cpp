#include <bits/stdc++.h>

using namespace std;

/* Maximum subarray sum */
// https://leetcode.com/problems/maximum-subarray/

// Brute 
// TC - O(n * n * n), SC - O(1)
int max_subarray_sum(vector<int>& v, int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += v[k];
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}

// Better 
// TC - O(n * n), SC - O(1)
int max_subarray_sum(vector<int>& v, int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];
            ans = max(ans, sum);
        }
    }
    return ans;
}

// Kadane's Algorithm (Optimal)
// TC - O(n), SC - O(1)
int max_subarray_sum(vector<int>& v, int n) {
    if (n == 0) {
        return 0;
    }
    int ans = v[0], sum = v[0], l = 0;
    // Variables to store the actual subarray indices if needed
    int idx_l = 0, idx_r = 0; 
    for (int r = 1; r < n; r++) {
        if (sum + v[r] < v[r]) {
            sum = v[r], l = r;
        } else {
            sum += v[r];
        }
        if (sum > ans) {
            ans = sum, idx_l = l, idx_r = r;
        }
    }  
    return ans;
}