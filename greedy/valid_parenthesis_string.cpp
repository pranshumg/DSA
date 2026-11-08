#include <bits/stdc++.h>

using namespace std;

/* valid parenthesis string */
// https://leetcode.com/problems/valid-parenthesis-string/

bool rec(string& s, int idx, int cnt) {
    if (cnt < 0) {
        return false;
    }
    if (idx == int(s.size())) {
        return cnt == 0;
    }
    if (s[idx] == '(') return rec(s, idx + 1, cnt + 1);
    if (s[idx] == ')') return rec(s, idx + 1, cnt - 1);
    return (rec(s, idx + 1, cnt + 1) || rec(s, idx + 1, cnt - 1) || rec(s, idx + 1, cnt));
}   

// TC - O(3^n), SC - O(n)
bool check(string s) {
    return rec(s, 0, 0);
}

// TC - O(n), SC - O(n)
bool check(string s) {
    stack<int> open, asterisk;
    for (int i = 0; i < int(s.size()); i++) {
        if (s[i] == '(') {
            open.push(i);
        } else if (s[i] == '*') {
            asterisk.push(i);
        } else {
            if (!open.empty()) {
                open.pop();
            } else if (!asterisk.empty()) {
                asterisk.pop();
            } else {
                return false;
            }
        }
    }
    while (!open.empty() && !asterisk.empty()) {
        if (open.top() > asterisk.top()) {
            return false;
        }
        open.pop();
        asterisk.pop();
    }
    return open.empty();
}

// TC - O(n), SC - O(1)
bool check(string s) {
    int mn = 0, mx = 0;
    for (char c : s) {
        if (c == '(') {
            mn++;
            mx++;
        } else if (c == ')') {
            mn--;
            mx--;
        } else {
            mn--;
            mx++;
        }
        if (mn < 0) mn = 0;
        if (mx < 0) return false;
    }
    return mn == 0;
}