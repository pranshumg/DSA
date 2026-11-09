#include <bits/stdc++.h>

using namespace std;

/* maximum consecutive ones 3 */
// https://leetcode.com/problems/max-consecutive-ones-iii/

// TC - O(n^2), SC - O(1)
int longest_ones(vector<int>& v, int k) {
    int ans = 0;
    for (int i = 0; i < int(v.size()); i++) {
        int zero = 0;
        for (int j = i; j < int(v.size()); j++) {
            if (v[j] == 0) zero++;
            if (zero > k) break;
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

// TC - O(n log (k + 1)), SC - O(k + 1)
int longest_ones(vector<int>& v, int k) {
    set<int> zero;
    int ans = 0;
    for (int l = 0, r = 0; r < int(v.size()); r++) {
        if (v[r] == 0) {
            zero.insert(r);
        }
        if (int(zero.size()) > k) {
            auto it = zero.begin();
            l = *it + 1;
            zero.erase(it);
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// TC - O(n), SC - O(1)
int longest_ones(vector<int>& v, int k) {
    int zero = 0, ans = 0;
    for (int l = 0, r = 0; r < int(v.size()); r++) {
        if (v[r] == 0) zero++;
        while (zero > k) {
            if (v[l] == 0) zero--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// TC - O(n), SC - O(1)
int longest_ones(vector<int>& v, int k) {
    int zero = 0, ans = 0;
    for (int l = 0, r = 0; r < int(v.size()); r++) {
        if (v[r] == 0) zero++;
        if (zero > k) {
            if (v[l] == 0) zero--;
            l++;
        }
        if (zero <= k) {
            ans = max(ans, r - l + 1);
        }
    }
    return ans;
}