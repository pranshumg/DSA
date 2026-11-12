#include <bits/stdc++.h>

using namespace std;

/* count number of nice subarrays */
// https://leetcode.com/problems/count-number-of-nice-subarrays/

// TC - O(n^2), SC - O(1)
int number(vector<int>& v, int k) {
    int ans = 0;
    for (int i = 0; i < int(v.size()); i++) {
        int odd = 0;
        for (int j = i; j < int(v.size()); j++) {
            if (v[j] & 1) odd++;
            if (odd > k) break;
            if (odd == k) ans++;
        }
    }
    return ans;
}

// TC - O(n), SC - O(1)
int number(vector<int>& v, int k) {
    auto f = [&](int x) -> int {
        int cnt = 0, odd = 0;
        if (x < 0) return 0;
        for (int l = 0, r = 0; r < int(v.size()); r++) {
            if (v[r] & 1) odd++;
            while (odd > x) {
                if (v[l] & 1) odd--;
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    };
    return f(k) - f(k - 1);
}