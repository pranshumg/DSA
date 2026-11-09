#include <bits/stdc++.h>

using namespace std;

/* maximum points you can obtain from cards */
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// TC - O(k), SC - O(1)
int max_score(vector<int>& v, int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += v[i];
    }
    int ans = sum;
    for (int l = k - 1, r = int(v.size()) - 1; l >= 0; l--, r--) {
        sum += v[r];
        sum -= v[l];
        ans = max(ans, sum);
    }
    return ans;
}