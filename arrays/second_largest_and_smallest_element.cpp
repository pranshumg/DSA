#include <bits/stdc++.h>

using namespace std;

/* Second Largest element */

// TC - O(n log n), SC - O(1)
int second_largest_element(vector<int>& v, int n) {
    sort(v.begin(), v.end());
    int largest = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] != largest) {
            return v[i];
        }
    }
    return INT_MIN;
}

// TC - O(n), SC - O(1)
int second_largest_element(vector<int>& v, int n) {
    int largest = v[0], second_largest = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (v[i] > largest) {
            largest = v[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] > second_largest && v[i] != largest) {
            second_largest = v[i];
        }
    }
    return second_largest;
}

// TC - O(n), SC - O(1)
int second_largest_element(vector<int>& v, int n) {
    int largest = v[0], second_largest = INT_MIN;
    for (int i = 1; i < n; i++) {
        if (v[i] > largest) {
            second_largest = largest;
            largest = v[i];
        } else if (v[i] < largest && v[i] > second_largest) {
            second_largest = v[i];
        }
    }
    return second_largest;
}

/* Second Smallest element */

// TC - O(n log n), SC - O(1)
int second_smallest_element(vector<int>& v, int n) {
    sort(v.begin(), v.end());
    int smallest = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] != smallest) {
            return v[i];
        }
    }
    return INT_MAX;
}

// TC - O(n), SC - O(1)
int second_smallest_element(vector<int>& v, int n) {
    int smallest = v[0], second_smallest = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (v[i] < smallest) {
            smallest = v[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] < second_smallest && v[i] != smallest) {
            second_smallest = v[i];
        }
    }
    return second_smallest;
}

// TC - O(n), SC - O(1)
int second_smallest_element(vector<int>& v, int n) {
    int smallest = v[0], second_smallest = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (v[i] < smallest) {
            second_smallest = smallest;
            smallest = v[i];
        } else if (v[i] > smallest && v[i] < second_smallest) {
            second_smallest = v[i];
        }
    }
    return second_smallest;
}