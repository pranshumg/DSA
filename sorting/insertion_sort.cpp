#include <bits/stdc++.h>

using namespace std;

/* Insertion sort */

// TC - O(n * n), SC - O(1)
void insertion_sort(vector<int>& v, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && v[j - 1] > v[j]) {
            swap(v[j - 1], v[j]);
            j--;
        }
    }
}