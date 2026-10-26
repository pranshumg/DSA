#include <bits/stdc++.h>

using namespace std;

/* Reverse an array */

// TC - O(n), SC - O(n)
void reverse_array(vector<int>& v, int l, int r) {
    if (l >= r) {
        return;
    }
    reverse_array(v, l + 1, r - 1);
    swap(v[l], v[r]);
}