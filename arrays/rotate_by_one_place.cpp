#include <bits/stdc++.h>

using namespace std;

/* Rotate array by one place */

// TC - O(n), SC - O(1)
void rotate_left_by_one_place(vector<int>& v, int n) {
    int tmp = v[0];
    for (int i = 1; i < n; i++) {
        v[i - 1] = v[i];
    }
    v[n - 1] = tmp;
}

// TC - O(n), SC - O(1)
void rotate_right_by_one_place(vector<int>& v, int n) {
    int tmp = v[n - 1];
    for (int i = n - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = tmp;
}