#include <bits/stdc++.h>

using namespace std;

/* Sum of beauty of all substrings */
// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

// TC - O(n^2), SC - O(1)
int beauty_sum(string s) {
    int ans = 0;
    for (int i = 0; i < int(s.size()); i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < int(s.size()); j++) {
            freq[s[j] - 'a']++;
            int mn = INT_MAX, mx = INT_MIN;
            for (int i : freq) {
                if (i) {
                    mn = min(mn, i);
                    mx = max(mx, i);
                }
            }
            ans += mx - mn;
        }
    }
    return ans;
}