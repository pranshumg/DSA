#include <bits/stdc++.h>

using namespace std;

/* Valid anagram */
// https://leetcode.com/problems/valid-anagram/

// TC - O(n log n), SC - O(1)
bool is_anagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// TC - O(n), SC - O(1)
bool is_anagram(string s, string t) {
    if (int(s.size()) != int(t.size())) {
        return false;
    }
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    for (char c : t) {
        freq[c - 'a']--;
        if (freq[c - 'a'] < 0) return false;
    }
    return true;
}