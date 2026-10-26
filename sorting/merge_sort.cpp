#include <bits/stdc++.h>

using namespace std;

/* Merge Sort */

void merge(vector<int>& v, int low, int mid, int high) {
    vector<int> tmp;
    int i = low, j = mid + 1;
    while (i <= mid && j <= high) {
        if (v[i] <= v[j]) {
            tmp.push_back(v[i++]);
        } else {
            tmp.push_back(v[j++]);
        }
    }
    while (i <= mid) {
        tmp.push_back(v[i++]);
    }
    while (j <= high) {
        tmp.push_back(v[j++]);
    }
    for (int i = low; i <= high; i++) {
        v[i] = tmp[i - low];
    }
}

// TC - O(n log n), SC - O(n)
void merge_sort(vector<int>& v, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    merge_sort(v, low, mid);
    merge_sort(v, mid + 1, high);
    merge(v, low, mid, high);
}