#include <bits/stdc++.h>

using namespace std;

/* Find the nth root of an integer */

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) {
            ans *= x;
        }
        x *= x;
        y >>= 1;
    }
    return ans;
}

// TC - O(log m * log n), SC - O(1)
int nth_root(int n, int m) {
    if (m == 1) return 1;
    int low = 1, high = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int root = power(mid, n);
        if (root == m) {
            return mid; 
        } else if (root < m) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }
    return -1;
}