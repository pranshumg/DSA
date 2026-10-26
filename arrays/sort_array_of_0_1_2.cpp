#include <bits/stdc++.h>

using namespace std;

/* Sort an array of 0's, 1's and 2's */
// https://leetcode.com/problems/sort-colors/

// Brute 
// TC - O(n log n), SC - O(1)
void sort_array(vector<int>& v, int n) {
    sort(v.begin(), v.end());
}

// Better Approach using Counting
// TC - O(n), SC - O(1)
void sort_array(vector<int>& v, int n) {
    int zero = 0, one = 0, two = 0;  
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            zero++;
        } else if (v[i] == 1) {
            one++;
        } else {
            two++;
        }
    }
    for (int i = 0; i < zero; i++) {
        v[i] = 0;
    }
    for (int i = zero; i < zero + one; i++) {
        v[i] = 1;
    }
    for (int i = zero + one; i < n; i++) {
        v[i] = 2;
    }
}

// Dutch National Flag Algorithm (Optimal) 
// TC - O(n), SC - O(1)
void sort_array(vector<int>& v, int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (v[mid] == 0) {
            swap(v[low++], v[mid++]);
        } else if (v[mid] == 1) {
            mid++;
        } else {
            swap(v[mid], v[high--]);
        }
    }
}