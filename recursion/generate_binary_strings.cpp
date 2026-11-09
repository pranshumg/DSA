#include <bits/stdc++.h>

using namespace std;

/* Generate binary strings without consecutive ones */

void rec(int n, string cur, vector<string>& res) {
    if (int(cur.size()) == n) {
        res.push_back(cur);
        return;
    }
    rec(n, cur + '0', res);
    if (cur.empty() || cur.back() != '1') {
        rec(n, cur + '1', res);
    }
}

// TC - O(2^n), SC - O(n)
vector<string> generate_binary_strings(int n) {
    vector<string> res;
    rec(n, "", res);
    return res;
}