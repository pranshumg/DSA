#include <bits/stdc++.h>

using namespace std;

/* Move zeros to end */
// https://leetcode.com/problems/move-zeroes/

// Brute 
// TC - O(n), SC - O(n)
void move_zeros_to_end(vector<int>& v, int n) {
    vector<int> tmp;
    for (int i = 0; i < n; i++) {
        if (v[i]) {
            tmp.push_back(v[i]);
        }
    }
    for (int i = 0; i < int(tmp.size()); i++) {
        v[i] = tmp[i];
    }
    for (int i = int(tmp.size()); i < n; i++) {
        v[i] = 0;
    }
}

// Optimal 
// TC - O(n), SC - O(1)
void move_zeros_to_end(vector<int>& v, int n) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (!v[i]) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        return;
    }
    for (int i = j + 1; i < n; i++) {
        if (v[i]) {
            swap(v[i], v[j++]);
        }
    }
}