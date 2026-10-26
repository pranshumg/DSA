#include <bits/stdc++.h>

using namespace std;

/* Subset sum */

void generate(int idx, int n, int sum, vector<int>& v, vector<int>& res) {
    if (idx >= n) {
        res.push_back(sum);
        return;
    }
    generate(idx + 1, n, sum + v[idx], v, res);
    generate(idx + 1, n, sum, v, res);
}

// TC - O(2^n), SC - O(2^n)
vector<int> subset_sum(vector<int>& v, int n) {
    vector<int> res;
    generate(0, n, 0, v, res);
    sort(res.begin(), res.end());
    return res;
}