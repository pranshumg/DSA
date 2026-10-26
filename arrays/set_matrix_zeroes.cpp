#include <bits/stdc++.h>

using namespace std;

/* Set matrix zeros */
// https://leetcode.com/problems/set-matrix-zeroes/

/* Helper functions for Brute Force */
void mark_row(vector<vector<int>>& v, int i, int m) {
    for (int j = 0; j < m; j++) {
        if (v[i][j] != 0) {
            v[i][j] = -1;
        }
    }
}

void mark_col(vector<vector<int>>& v, int j, int n) {
    for (int i = 0; i < n; i++) {
        if (v[i][j] != 0) {
            v[i][j] = -1;
        }
    }
}

// Brute  
// TC - O(n * m * (n + m)), SC - O(1)
void set_zero(vector<vector<int>>& v, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                mark_row(v, i, m);
                mark_col(v, j, n);
            }
        }
    }
    // Replace temporary marker -1 with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == -1) {
                v[i][j] = 0;
            }
        }
    }
}

// Better Approach 
// TC - O(n * m), SC - O(n+m)
void set_zero(vector<vector<int>>& v, int n, int m) {
    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                v[i][j] = 0;
            }
        }
    }
}

// Optimal Approach 
// TC - O(n * m), SC - O(1)
void set_zero(vector<vector<int>>& v, int n, int m) {
    int col0 = 1;
    // Step 1: Traverse the matrix and mark 1st row & 1st col accordingly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                // mark i-th row
                v[i][0] = 0;
                // mark j-th column
                if (j != 0) {
                    v[0][j] = 0;
                } else {
                    col0 = 0;
                }
            }
        }
    }
    // Step 2: Mark with 0 from (1,1) to (n - 1, m - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (v[i][0] == 0 || v[0][j] == 0) {
                v[i][j] = 0;
            }
        }
    }
    // Step 3: Handle the first row
    if (v[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            v[0][j] = 0;
        }
    }
    // Step 4: Handle the first column
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            v[i][0] = 0;
        }
    }
}