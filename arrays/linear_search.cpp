#include <bits/stdc++.h>

using namespace std;

/* Linear search */

// TC - O(n), SC - O(1)
int linear_search(vector<int>& v, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (v[i] == k) {
            return i;
        }
    }
    return -1;
}