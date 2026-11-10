#include <bits/stdc++.h>

using namespace std;

/* longest substring with at most k distinct characters */
// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

// TC - O(n^2 log(k + 1)), SC - O(k)
int longest(string& s, int k) {
    int ans = 0;
    for (int i = 0; i < int(s.size()); i++) {
        set<char> st;
        for (int j = i; j < int(s.size()); j++) {
            st.insert(s[j]);
            if (int(st.size()) > k) {
                break;
            }
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

// TC - O(n log (k + 1)), SC - O(k)
int longest(string& s, int k) {
    int ans = 0;
    map<char, int> mp;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        mp[s[r]]++;
        while (int(mp.size()) > k) {
            mp[s[l]]--;
            if (!mp[s[l]]) {
                mp.erase(s[l]);
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// TC - O(n log (k + 1)), SC - O(k)
int longest(string& s, int k) {
    int ans = 0;
    map<char, int> mp;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        mp[s[r]]++;
        if (int(mp.size()) > k) {
            mp[s[l]]--;
            if (!mp[s[l]]) {
                mp.erase(s[l]);
            }
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}