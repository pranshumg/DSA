#include <bits/stdc++.h>

using namespace std;

/* Insertion sort (recursion) */

// TC - O(n * n), SC - O(n)
void insertion_sort_rec(vector<int>& v, int i, int n) {
    if (i == n) {
        return;
    }
    int j = i;
    while (j > 0 && v[j - 1] > v[j]) {
        swap(v[j - 1], v[j]);
        j--;
    }
    insertion_sort_rec(v, i + 1, n);
}