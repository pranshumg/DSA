#include <bits/stdc++.h>

using namespace std;

/* minimum window substring */
// https://leetcode.com/problems/minimum-window-substring/

// TC - O(n^2 + m), SC - O(1)
string min_window(string& s, string& t) {
    map<char, int> mp1;
    for (char c : t) {
        mp1[c]++;
    }
    int x = -1, y = -1;
    for (int i = 0; i < int(s.size()); i++) {
        map<char, int> mp2;
        for (int j = i; j < int(s.size()); j++) {
            if (mp1.count(s[j])) {
                mp2[s[j]]++;
            }
            if (int(mp1.size()) == int(mp2.size())) {
                bool b = true;
                for (auto& [c, cnt] : mp2) {
                    if (cnt < mp1[c]) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    if (x == -1 || y - x > j - i) {
                        x = i;
                        y = j;
                    }
                    break;
                }
            }
        }
    }
    return (x == -1 ? "" : s.substr(x, y - x + 1));
}

// TC - O(n + m), SC - O(n)
string min_window(string& s, string& t) {
    map<char, int> mp1;
    for (char c : t) {
        mp1[c]++;
    }
    map<char, int> mp2;
    deque<int> dq;
    int x = -1, y = -1;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        if (mp1.count(s[r])) {
            mp2[s[r]]++;
            dq.push_back(r);
            l = dq[0];
        }
        while (!dq.empty() && mp2[s[dq[0]]] > mp1[s[dq[0]]]) {
            mp2[s[dq[0]]]--;
            dq.pop_front();
            l = dq[0];
        }
        if (int(mp1.size()) == int(mp2.size())) {
            bool b = true;
            for (auto& [c, cnt] : mp2) {
                if (cnt < mp1[c]) {
                    b = false;
                    break;
                }
            }
            if (b) {
                if (x == -1 || y - x > r - l) {
                    x = l;
                    y = r;
                }
            }
        }
    }
    return (x == -1 ? "" : s.substr(x, y - x + 1));
}

// TC - O(n), SC - O(1)
string min_window(string& s, string& t) {
    vector<int> v(256, 0);
    for (unsigned char c : t) {
        v[c]++;
    }
    int len = INT32_MAX, cnt = 0, start = 0;
    for (int l = 0, r = 0; r < int(s.size()); r++) {
        unsigned char c = s[r];
        if (v[c] > 0) cnt++;
        v[c]--;
        while (cnt == int(t.size())) {
            if (len > r - l + 1) {
                len = r - l + 1;
                start = l;
            }
            unsigned char d = s[l];
            v[d]++;
            if (v[d] > 0) {
                cnt--;
            }
            l++;
        }
    }
    return (start == -1 ? "" : s.substr(start, len));
}