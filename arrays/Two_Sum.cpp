#include <bits/stdc++.h>

using namespace std;

/* Two Sum */
// https://leetcode.com/problems/two-sum/

// Brute 
// TC - O(n * n), SC - O(1)
vector<int> two_sum(vector<int>& v, int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] + v[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// Better 
// TC - O(n), SC - O(n)
vector<int> two_sum(vector<int>& v, int n, int target) {
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.find(target - v[i]) != mp.end()) {
            return {mp[target - v[i]], i};
        }
        mp[v[i]] = i;
    }
    return {};
}

// Optimal 
// TC - O(n log n), SC - O(1)
// NOTE: This approach requires sorting, which changes the original indices.
// If you need indices, you must store pairs {value, index} before sorting,
// which makes Space Complexity O(n).
bool two_sum(vector<int>& v, int n, int target) {
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (i < j) {
        int sum = v[i] + v[j];
        if (sum < target) {
            i++;
        } else if (sum > target) {
            j--;
        } else {
            return true;
        }
    }
    return false;
}