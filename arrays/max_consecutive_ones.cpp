#include <bits/stdc++.h>

using namespace std;

/* Maximum consecutive ones */
// https://leetcode.com/problems/max-consecutive-ones/

// TC - O(n), SC - O(1)
int max_consecutive_ones(vector<int>& v, int n) {
    int ans = 0, cnt = 0;
    for (auto& a : v) {
        if (a == 1) {
            cnt++;
        } else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    return ans;
}