#include <bits/stdc++.h>

using namespace std;

/* fruit into baskets */
// https://leetcode.com/problems/fruit-into-baskets/

// TC - O(n^2), SC - O(1)
int total(vector<int>& v) {
    int ans = 0;
    for (int i = 0; i < int(v.size()); i++) {
        set<int> st;
        for (int j = i; j < int(v.size()); j++) {
            st.insert(v[j]);
            if (int(st.size()) > 2) {
                break;
            }
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
} 

// TC - O(n), SC - O(1);
int total(vector<int>& v) {
    int ans = 0;
    map<int, int> mp;
    for (int l = 0, r = 0; r < int(v.size()); r++) {
        mp[v[r]]++;
        while (int(mp.size()) > 2) {
            mp[v[l]]--;
            if (!mp[v[l]]) {
                mp.erase(v[l]);
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// TC - O(n), SC - O(1);
int total(vector<int>& v) {
    int ans = 0;
    map<int, int> mp;
    for (int l = 0, r = 0; r < int(v.size()); r++) {
        mp[v[r]]++;
        if (int(mp.size()) > 2) {
            mp[v[l]]--;
            if (!mp[v[l]]) {
                mp.erase(v[l]);
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// TC - O(n), SC - O(1)
int total(vector<int>& v) {
    if (v.empty()) {
        return 0;
    }
    int ans = 1;
    int x = 0, y = -1, el1 = v[0], el2 = -1;
    for (int l = 0, r = 1; r < int(v.size()); r++) {
        if (v[r] != el1 && el2 == -1) {
            el2 = v[r];
            y = r;
        }
        if (v[r] == el1) {
            x = r;   
        } else if (v[r] == el2) {
            y = r;
        } else {
            if (x < y) {
                l = x + 1;
                el1 = v[l];
                x = y;
                el2 = v[r];
                y = r;
            } else {
                l = y + 1;
                el2 = v[l];
                y = x;
                el1 = v[r];
                x = r;
            }
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}