#include <bits/stdc++.h>

using namespace std;

/* Best time to buy and sell stock */
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// TC - O(n), SC - O(1)
int max_profit(vector<int>& v, int n) {
    int mn = v[0], profit = 0;
    for (int i = 0; i < n; i++) {
        int cost = v[i] - mn;
        profit = max(profit, cost);
        mn = min(mn, v[i]);
    }
    return profit;
}