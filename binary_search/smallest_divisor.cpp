#include <bits/stdc++.h>

using namespace std;

/* Find the smallest divisor given a threshold */
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

int sum(vector<int>& v, int div) {
    int s = 0;
    for (int i : v) {
        s += (i + div - 1) / div;
    }
    return s;
}

// TC - O(n log(max(v))), SC - O(1)
int divisor(vector<int>& v, int n, int threshold) {
    int low = 1, high = *max_element(v.begin(), v.end());
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sum(v, mid) <= threshold) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}