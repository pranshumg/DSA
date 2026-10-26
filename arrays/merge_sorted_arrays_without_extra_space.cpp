#include <bits/stdc++.h>

using namespace std;

/* Merge sorted arrays without extra space */
// https://leetcode.com/problems/merge-sorted-array/

// Optimal 1 
// TC - O(min(m, n)) + O(m log m + n log n), SC - O(1)
// This approach swaps elements and then re-sorts both arrays.
void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
    int l = m - 1, r = 0;
    while (l >= 0 && r < n) {
        if (v1[l] > v2[r]) {
            swap(v1[l--], v2[r++]);
        } else {
            break;
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}

// Optimal 2 (Gap Method) 
// TC - O((m + n) log (m + n)), SC - O(1)
// This is based on Shell Sort logic.
void merge_gap(vector<int>& v1, int m, vector<int>& v2, int n) {
    int len = n + m;
    int gap = (len / 2) + (len % 2); // Same as ceil(len / 2)
    while (gap > 0) {
        int l = 0;
        int r = l + gap;
        while (r < len) {
            // Case 1: Both pointers in the first array (v1)
            if (r < m) {
                if (v1[l] > v1[r]) {
                    swap(v1[l], v1[r]);
                }
            }
            // Case 2: Left pointer in v1, Right pointer in v2
            else if (l < m && r >= m) {
                if (v1[l] > v2[r - m]) {
                    swap(v1[l], v2[r - m]);
                }
            }
            // Case 3: Both pointers in the second array (v2)
            else {
                if (v2[l - m] > v2[r - m]) {
                    swap(v2[l - m], v2[r - m]);
                }
            }
            l++, r++;
        }
        if (gap == 1) {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }
}