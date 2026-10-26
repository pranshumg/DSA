#include <bits/stdc++.h>

using namespace std;

/* Bubble sort (recursion) */

// TC - O(n * n), SC - O(n)
void bubble_sort_rec(vector<int>& v, int i, int n) {
    if (i == n - 1) {
        return;
    }
    bool did_swap = false;
    for (int j = 0; j < n - 1 - i; j++) {
        if (v[j] > v[j + 1]) {
            swap(v[j], v[j + 1]);
            did_swap = true;
        }
    }
    if (!did_swap) {
        return;
    }
    bubble_sort_rec(v, i + 1, n);
}