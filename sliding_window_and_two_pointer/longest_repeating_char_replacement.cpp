#include <bits/stdc++.h>

using namespace std;

/* longest repeating character replacement */
// https://leetcode.com/problems/longest-repeating-character-replacement/

// TC - O(n^2), SC - O(1)
int char_replacement(string& s, int k) {
    int ans = 0;
    for (int i = 0; i < int(s.size()); i++) {
        vector<int> freq(26, 0);
        int mx = 0;
        for (int j = i; j < int(s.size()); j++) {
            freq[s[j] - 'A']++;
            mx = max(mx, freq[s[j] - 'A']);
            if (j - i + 1 - mx > k) {
                break;
            }
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

// TC - O(n), SC - O(1)
int char_replacement(string& s, int k) {
    int ans = 0;
    vector<int> freq(26, 0);
    int mx = 0;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        freq[s[r] - 'A']++;
        mx = max(mx, freq[s[r] - 'A']);
        while (r - l + 1 - mx > k) {
            freq[s[l++] - 'A']--;
            mx = 0;
            for (int i = 0; i < 26; i++) {
                mx = max(mx, freq[i]);
            }
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}

// TC - O(n), SC - O(1)
int char_replacement(string& s, int k) {
    int ans = 0;
    vector<int> freq(26, 0);
    int mx = 0;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        freq[s[r] - 'A']++;
        mx = max(mx, freq[s[r] - 'A']);
        if (r - l + 1 - mx > k) {
            freq[s[l++] - 'A']--;
        }
        ans = max(ans, r - l + 1);
    }
    return ans;
}