#include <bits/stdc++.h>

using namespace std;

/* Selection sort */

// TC - O(n * n), SC - O(1)
void selection_sort(vector<int>& v, int n) {
    for (int i = 0; i < n - 1; i++) {
        int mn_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[mn_idx]) {
                mn_idx = j;
            }
        }
        swap(v[i], v[mn_idx]);
    }
}