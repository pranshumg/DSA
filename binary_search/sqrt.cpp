#include <bits/stdc++.h>

using namespace std;

/* Finds the floor of the square root of n */

// TC - O(log n), SC - O(1)
int sqrt(int n) {
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}