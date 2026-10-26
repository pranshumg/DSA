#include <bits/stdc++.h>

using namespace std;

/* Split array into k subarrays such that the maximum subarray sum is minimum */
// https://leetcode.com/problems/split-array-largest-sum/

int check(vector<int>& v, int mx) {
    int cnt = 1, sum = 0;
    for (int i : v) {
        if (sum + i <= mx) {
            sum += i;
        } else {
            sum = i;
            cnt++;
        }
    }
    return cnt;
}

// TC - O(n * log(sum(v) - max(v))), SC - O(1)
int split(vector<int>& v, int n, int k) {
    if (n < k) return -1;
    int low = 0, high = 0;
    for (int i : v) {
        low = max(low, i);
        high += i;
    }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(v, mid) <= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}