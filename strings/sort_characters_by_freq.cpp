#include <bits/stdc++.h>

using namespace std;

/* Sort characters by frequency */
// https://leetcode.com/problems/sort-characters-by-frequency/

// TC - O(n log k), SC - O(n + k) where k is the number of unique characters
string frequency_sort(string s) {
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    vector<pair<char, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    string res = "";
    for (auto& [c, freq] : v) {
        res += string(freq, c);
    }
    return res;
}