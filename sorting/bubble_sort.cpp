#include <bits/stdc++.h>

using namespace std;

/* Bubble sort */

// TC - O(n * n), SC - O(1)
void bubble_sort(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        bool did_swap = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                did_swap = true;
            }
        }
        if (!did_swap) {
            break;
        }
    }
}