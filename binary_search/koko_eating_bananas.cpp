#include <bits/stdc++.h>

using namespace std;

/* Koko eating bananas */
// https://leetcode.com/problems/koko-eating-bananas/

int time(vector<int>& v, int h) {
    int ans = 0;
    for (int i : v) {
        ans += (i + h - 1) / h;
    }
    return ans;
}

// TC - O(n * log m) where m is the maximum no. of bananas in a single pile, SC - O(1)
int min_eating_speed(vector<int>& v, int n, int h) {
    int low = 1, high = *max_element(v.begin(), v.end());
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (time(v, mid) <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}