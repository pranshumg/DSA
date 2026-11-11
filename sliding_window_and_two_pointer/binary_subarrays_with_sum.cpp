#include <bits/stdc++.h>

using namespace std;

/* binary subarrays with sum */
// https://leetcode.com/problems/binary-subarrays-with-sum/

// TC - O(n^2), SC - O(1)
int number(vector<int>& v, int goal) {
    int ans = 0;
    for (int i = 0; i < int(v.size()); i++) {
        int sum = 0;
        for (int j = i; j < int(v.size()); j++) {
            sum += v[j];
            if (sum > goal) {
                break;
            }
            if (sum == goal) {
                ans++;
            }
        }
    }
    return ans;
}

// TC - O(n log n), SC - O(n)
int number(vector<int>& v, int goal) {
    int ans = 0;
    map<int, int> mp;
    mp[0]++;
    int sum = 0;
    for (int i = 0; i < int(v.size()); i++) {
        sum += v[i];
        ans += mp[sum - goal];
        mp[sum]++;
    }
    return ans;
}

// TC - O(n), SC - O(1)
int number(vector<int>& v, int goal) {
    auto f = [&](int x) -> int {
        if (x < 0) {
            return 0;
        }
        int cnt = 0, sum = 0;
        for (int l = 0, r = 0; r < int(v.size()); r++) {
            sum += v[r];
            while (sum > x) {
                sum -= v[l++];
            }
            cnt += r - l + 1;
        }
        return cnt;
    };
    return f(goal) - f(goal - 1);
}