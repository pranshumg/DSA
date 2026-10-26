#include <bits/stdc++.h>

using namespace std;

/* Capacity to ship packages within d days */
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

int total_days(vector<int>& v, int cap) {
    int days = 1, weight = 0;
    for (int i : v) {
        if (weight + i > cap) {
            days++;
            weight = i;
        } else {
            weight += i;
        }
    }
    return days;
}

// TC - O(n * log(sum(v) - max(v))), SC - O(1)
int capacity(vector<int>& v, int days) {
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (total_days(v, mid) <= days) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}