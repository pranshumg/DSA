#include <bits/stdc++.h>

using namespace std;

/* To check array is sorted in non-decreasing order */

// TC - O(n), SC - O(1)
bool is_sorted(vector<int>& v, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}