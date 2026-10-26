#include <bits/stdc++.h>

using namespace std;

/* Next permutation */
// https://leetcode.com/problems/next-permutation/

// Using STL
// TC - O(n), SC - O(1)
void Next_permutation(vector<int>& v, int n) {
    next_permutation(v.begin(), v.end());
}

// Optimal Manual Implementation
// TC - O(n), SC - O(1)
void Next_permutation(vector<int>& v, int n) {
    int idx = -1;
    // Step 1: Find the break point: the first index from the back
    // where element is smaller than the next one.
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1]) {
            idx = i;
            break;
        }
    }
    // If no break point is found, the array is in descending order (last permutation).
    // Reverse to get the first permutation (ascending order).
    if (idx == -1) {
        reverse(v.begin(), v.end());
        return;
    }
    // Step 2: Find the smallest element in the suffix (right of idx)
    // that is greater than v[idx].
    for (int i = n - 1; i > idx; i--) {
        if (v[i] > v[idx]) {
            swap(v[i], v[idx]);
            break;
        }
    }
    // Step 3: Reverse the suffix to make it the smallest possible arrangement.
    reverse(v.begin() + idx + 1, v.end());
}