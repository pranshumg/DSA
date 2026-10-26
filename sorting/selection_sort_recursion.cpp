#include <bits/stdc++.h>

using namespace std;

/* Selection sort (recursion) */

// TC - O(n * n), SC - O(n)
void selection_sort_rec(vector<int>& v, int i, int n) {
    if (i == n - 1) {
        return;
    }
    int mn_idx = i;
    for (int j = i + 1; j < n; j++) {
        if (v[j] < v[mn_idx]) {
            mn_idx = j;
        }
    }
    swap(v[i], v[mn_idx]);
    selection_sort_rec(v, i + 1, n);
}