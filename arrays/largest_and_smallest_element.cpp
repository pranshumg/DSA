#include <bits/stdc++.h>

using namespace std;

/* Largest element */

// Brute 
// TC - O(n log n), SC - O(1)
int largest_element(vector<int>& v, int n) {
    sort(v.begin(), v.end());
    return v[n - 1];
}

// Optimal 
// TC - O(n), SC - O(1)
int largest_element(vector<int>& v, int n) {
    int largest = v[0];
    for (int i = 1; i < n; i++) {
        largest = max(largest, v[i]);
    }
    return largest;
}

/* Smallest element */

// Brute 
// TC - O(n log n), SC - O(1)
int smallest_element(vector<int>& v, int n) {
    sort(v.begin(), v.end());
    return v[0];
}

// Optimal
// TC - O(n), SC - O(1)
int smallest_element(vector<int>& v, int n) {
    int smallest = v[0];
    for (int i = 1; i < n; i++) {
        smallest = min(smallest, v[i]);
    }
    return smallest;
}