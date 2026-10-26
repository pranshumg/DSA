#include <bits/stdc++.h>

using namespace std;

/* Rotate array by k places */
// https://leetcode.com/problems/rotate-array/

// Brute
// TC - O(n), SC - O(k)
void rotate_left_by_k_places(vector<int>& v, int n, int k) {
    k %= n;
    vector<int> tmp(v.begin(), v.begin() + k);
    for (int i = k; i < n; i++) {
        v[i - k] = v[i];
    }
    for (int i = n - k; i < n; i++) {
        v[i] = tmp[i - n - k];
    }
}

// Optimal
// TC - O(n), SC - O(1)
void rotate_left_by_k_places(vector<int>& v, int n, int k) {
    k %= n;
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    reverse(v.begin(), v.end());
}

// Brute
// TC - O(n), SC - O(k)
void rotate_right_by_k_places(vector<int>& v, int n, int k) {
    k %= n;
    vector<int> tmp(v.begin(), v.begin() + (n - k));
    for (int i = n - k; i < n; i++) {
        v[i - (n - k)] = v[i];
    }
    for (int i = k; i < n; i++) {
        v[i] = tmp[i - k];
    }
}

// Optimal 
// TC - O(n), SC - O(1)
void rotate_right_by_k_places(vector<int>& v, int n, int k) {
    k %= n;
    reverse(v.begin(), v.begin() + (n - k));
    reverse(v.begin() + (n - k), v.end());
    reverse(v.begin(), v.end());
}