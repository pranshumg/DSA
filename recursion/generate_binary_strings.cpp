#include <bits/stdc++.h>

using namespace std;

/* Generate binary strings without consecutive ones */

void solve(int n, string cur, vector<string>& res) {
    if (int(cur.size()) == n) {
        res.push_back(cur);
        return;
    }
    solve(n, cur + '0', res);
    if (cur.empty() || cur.back() != '1') {
        solve(n, cur + '1', res);
    }
}

// TC - O(2^n), SC - O(n)
vector<string> generate_binary_strings(int n) {
    vector<string> res;
    solve(n, "", res);
    return res;
}