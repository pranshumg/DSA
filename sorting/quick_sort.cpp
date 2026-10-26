#include <bits/stdc++.h>

using namespace std;

/* Quick Sort */

int partition(vector<int>& v, int low, int high) {
    int pivot = v[low];
    int i = low, j = high;
    while (i < j) {
        while (i <= high && v[i] <= pivot) i++;
        while (j >= low && v[j] > pivot) j--;
        if (i < j) swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}

// TC - O(n log n), SC - O(log n)
void quick_sort(vector<int>& v, int low, int high) {
    if (low >= high) return;
    int pivot_idx = partition(v, low, high);
    quick_sort(v, low, pivot_idx - 1);
    quick_sort(v, pivot_idx + 1, high);
}