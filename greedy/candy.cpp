#include <bits/stdc++.h>

using namespace std;

/* candy */
// https://leetcode.com/problems/candy/

// TC - O(n), SC - O(n)
int candy(vector<int>& v) {
    vector<int> left(int(v.size()), 1);
    for (int i = 1; i < int(v.size()); i++) {
        if (v[i] > v[i - 1]) {
            left[i] = left[i - 1] + 1;
        } 
    }
    vector<int> right(int(v.size()), 1);
    int ans = max(left.back(), right.back());
    for (int i = int(v.size()) - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]) {
            right[i] = right[i + 1] + 1;
        } 
        ans += max(left[i], right[i]);
    }
    return ans;
}

// TC - O(n), SC - O(n)
int candy(vector<int>& v) {
    vector<int> left(int(v.size()), 1);
    for (int i = 1; i < int(v.size()); i++) {
        if (v[i] > v[i - 1]) {
            left[i] = left[i - 1] + 1;
        } 
    }
    int right = 1, ans = left.back();
    for (int i = int(v.size()) - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]) {
            right++;
        } else {
            right = 1;
        }
        ans += max(left[i], right);
    }
    return ans;
}

// TC - O(n), SC - O(1)
int candy(vector<int>& v) {
    int ans = 1;
    for (int i = 1; i < int(v.size());) {
        if (v[i] == v[i - 1]) {
            ans++;
            i++;
            continue;
        }
        int peak = 1;
        while (i < int(v.size()) && v[i] > v[i - 1]) {
            ans += ++peak;
            i++;
        }
        int down = 1;
        while (i < int(v.size()) && v[i] < v[i - 1]) {
            ans += down++;
            i++;
        }
        if (down > peak) {
            ans += down - peak;
        }
    }
    return ans;
}