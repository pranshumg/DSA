#include <bits/stdc++.h>

using namespace std;

/* Count occurrences */

int first(vector<int>& v, int n, int target) {
    int low = 0, high = n - 1;
    int idx = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) {
            idx = mid;
            high = mid - 1;
        } else if (v[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}

int last(vector<int>& v, int n, int target) {
    int low = 0, high = n - 1;
    int idx = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] == target) {
            idx = mid;
            low = mid + 1;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return idx;
}

// TC - O(log n), SC - O(1)
int count(vector<int>& v, int n, int target) {
    int f = first(v, n, target);
    if (f == -1) {
        return 0;
    }
    return last(v, n, target) - f + 1;
}