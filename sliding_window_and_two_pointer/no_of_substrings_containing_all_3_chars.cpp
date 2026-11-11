#include <bits/stdc++.h>

using namespace std;

/* number of substrings containing all three characters */
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

// TC - O(n^2), SC - O(1)
int number(string& s) {
    int ans = 0;
    for (int i = 0; i < int(s.size()); i++) {
        vector<bool> hash(3, false);
        for (int j = i; j < int(s.size()); j++) {
            hash[s[j] - 'a'] = true;
            if (hash[0] && hash[1] && hash[2]) {
                ans += int(s.size()) - j;
                break;
            }
        }
    }
    return ans;
}

// TC - O(n), SC - O(1)
int number(string& s) {
    int cnt = 0;
    map<char, int> mp;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        mp[s[r]]++;
        while (int(mp.size()) > 2) {
            mp[s[l]]--;
            if (!mp[s[l]]) {
                mp.erase(s[l]);
            }
            l++;
        }
        cnt += r - l + 1;
    }
    int n = int(s.size());
    return n * (n + 1) / 2 - cnt; 
}

// TC - O(n), SC - O(1)
int number(string& s) {
    int ans = 0;
    vector<int> idx(3, -1);
    for (int i = 0; i < int(s.size()); i++) {
        idx[s[i] - 'a'] = i;
        if (idx[0] > -1 && idx[1] > -1 && idx[2] > -1) {
            ans += min({idx[0], idx[1], idx[2]}) + 1;
        }
    }
    return ans;
}