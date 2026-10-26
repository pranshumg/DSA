#include <bits/stdc++.h>

using namespace std;

/* Binary search */
// https://leetcode.com/problems/binary-search/

// Iterative 
// TC - O(log n), SC - O(1)
int Binary_search(vector<int>& v, int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) {
            return mid;
        } else if (v[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

// Recursive 
// TC - O(log n), SC - O(log n) due to recursion stack
int binary_search_rec(vector<int>& v, int target, int low, int high) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (v[mid] == target) {
        return mid;
    } else if (v[mid] > target) {
        return binary_search_rec(v, target, low, mid - 1);
    } else {
        return binary_search_rec(v, target, mid + 1, high);
    }
}