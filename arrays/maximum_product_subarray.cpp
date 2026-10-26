#include <bits/stdc++.h>

using namespace std;

/* Maximum Product Subarray */
// https://leetcode.com/problems/maximum-product-subarray/

// Brute 
// TC - O(n * n * n), SC - O(1)
int max_product(vector<int>& v, int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int prod = 1;
            for (int k = i; k <= j; k++) {
                prod *= v[k];
            }
            ans = max(ans, prod);
        }
    }
    return ans;
}

// Better 
// TC - O(n * n), SC - O(1)
int max_product(vector<int>& v, int n) {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = i; j < n; j++) {
            prod *= v[j];
            ans = max(ans, prod);
        }
    }
    return ans;
}

// Optimal 
// TC - O(n), SC - O(1)
// Note: This approach handles negative numbers by checking prefix and suffix products.
// If there are an even number of negatives, the full array is the answer.
// If odd, the answer lies on either side of one of the negatives.
int max_product(vector<int>& v, int n) {
    int pfx = 1, sfx = 1, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pfx == 0) {
            pfx = 1;
        }
        if (sfx == 0) {
            sfx = 1;
        }
        pfx *= v[i];
        sfx *= v[n - i - 1];
        ans = max(ans, max(pfx, sfx));
    }
    return ans;
}