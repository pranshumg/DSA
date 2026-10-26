#include <bits/stdc++.h>

using namespace std;

/* Print subsequences */

// TC - O(2^n * n), SC - O(2^n * n)
void subsequences(vector<int>& v, int idx, int n, vector<int>& res) {
    if (idx >= n) {
        for (auto& a : res) {
            cout << a << ' ';   
        }
        cout << '\n';
        return;
    }
    res.push_back(v[idx]);
    subsequences(v, idx + 1, n, res);
    res.pop_back();
    subsequences(v, idx + 1, n, res);
}