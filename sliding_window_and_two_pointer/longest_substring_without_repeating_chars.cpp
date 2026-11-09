#include <bits/stdc++.h>

using namespace std;

/* longest substring without repeating characters */
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// TC - O(n^2), SC - O(1)
int length(string& s) {
    int ans = 0;
    for (int i = 0; i < int(s.size()); i++) {
        vector<bool> hash(256, false);
        for (int j = i; j < int(s.size()); j++) {
            unsigned char c = s[j];
            if (hash[c]) break;
            ans = max(ans, j - i + 1);
            hash[c] = true;
        }
    }
    return ans;
}

// TC - O(n log k), SC - O(k), where k = number of distinct characters
int length(string& s) {
    int ans = 0;
    map<char, int> mp;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        mp[s[r]]++;
        while (int(mp.size()) < r - l + 1) {
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

// TC - O(n), SC - O(1)
int length(string& s) {
    int ans = 0;
    vector<int> hash(256, -1);
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        unsigned char c = s[r];
        if (hash[c] >= l) {
            l = hash[c] + 1;
        } 
        hash[c] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}