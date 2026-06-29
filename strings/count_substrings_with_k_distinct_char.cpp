#include <bits/stdc++.h>

using namespace std;

/* Count substrings with k distinct characters */

int at_most(string s, int k) {
    if (k < 0) {
        return 0;
    }
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
        ans += r - l + 1;
    }
    return ans;
}

// TC - O(n log m), SC - (m) where m is the number of distinct characters
int count_substrings(string s, int k) {
    return at_most(s, k) - at_most(s, k - 1);
}