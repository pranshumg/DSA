#include <bits/stdc++.h>

using namespace std;

/* subarrays with k different integers */
// https://leetcode.com/problems/subarrays-with-k-different-integers/

// TC - O(n^2 log(k + 1)), SC - O(k + 1) 
int subarrays(vector<int>& v, int k) {
    int ans = 0;
    for (int i = 0; i < int(v.size()); i++) {
        set<int> st;
        for (int j = i; j < int(v.size()); j++) {
            st.insert(v[j]);
            if (int(st.size()) > k) break;
            if (int(st.size()) == k) ans++;
        }
    }
    return ans;
}

// TC - O(n log(k + 1)), SC - O(k + 1)
int subarrays(vector<int>& v, int k) {
    auto f = [&](int x) -> int {
        if (x < 0) return 0;
        int cnt = 0;
        map<int, int> mp;
        for (int l = 0, r = 0; r < int(v.size()); r++) {
            mp[v[r]]++;
            while (int(mp.size()) > x) {
                mp[v[l]]--;
                if (!mp[v[l]]) {
                    mp.erase(v[l]);
                }
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    };
    return f(k) - f(k - 1);
}