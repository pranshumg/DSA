#include <bits/stdc++.h>

using namespace std;

// LeetCode: Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

/* Generate parentheses */

void solve(int n, string cur, int open, int close, vector<string>& res) {
    if ((int)cur.size() == 2 * n) {
        res.push_back(cur);
        return;
    }
    if (open < n) solve(n, cur + '(', open + 1, close, res);
    if (open > close) solve(n, cur + ')', open, close + 1, res);
}

// TC - O(2^n), SC - O(n)
vector<string> generate_parentheses(int n) {
    vector<string> res;
    solve(n, "", 0, 0, res);
    return res;
}