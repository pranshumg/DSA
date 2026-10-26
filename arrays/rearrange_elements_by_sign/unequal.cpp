#include <bits/stdc++.h>

using namespace std;

/* Rearrange unequal positive and negative elements by sign */

// TC - O(n), SC - O(n)
vector<int> rearrange_array(vector<int>& v, int n) {
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            pos.push_back(v[i]);
        } else {
            neg.push_back(v[i]);
        }
    }
    vector<int> res(n);
    if (int(pos.size()) > int(neg.size())) {
        for (int i = 0; i < int(neg.size()); i++) {
            res[2 * i] = pos[i];
            res[2 * i + 1] = neg[i];
        }
        int idx = int(neg.size()) * 2;
        for (int i = int(neg.size()); i < int(pos.size()); i++) {
            res[idx++] = pos[i];
        }
    } else {
        for (int i = 0; i < int(pos.size()); i++) {
            res[2 * i] = pos[i];
            res[2 * i + 1] = neg[i];
        }
        int idx = int(pos.size()) * 2;
        for (int i = int(pos.size()); i < int(neg.size()); i++) {
            res[idx++] = neg[i];
        }
    }
    return res;
}