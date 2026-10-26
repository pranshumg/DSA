#include <bits/stdc++.h>

using namespace std;

/* kth element of two sorted arrays */

// TC - O(log(min(m, n))), SC - O(1)
int kth_element(vector<int>& v1, int m, vector<int>& v2, int n, int k) {
    if (m > n) return kth_element(v2, n, v1, m, k);
    int low = max(0, k - n), high = min(m, k);
    while (low <= high) {
        int mid1 = low + (high - low) / 2;
        int mid2 = k - mid1;
        int l1 = mid1 > 0 ? v1[mid1 - 1] : INT_MIN;
        int l2 = mid2 > 0 ? v2[mid2 - 1] : INT_MIN;
        int r1 = mid1 < m ? v1[mid1] : INT_MAX;
        int r2 = mid2 < n ? v2[mid2] : INT_MAX;
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return -1; 
}