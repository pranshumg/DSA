#include <bits/stdc++.h>

using namespace std;

/* fractional knapsack */

// TC - O(n log n), SC - O(1)
double fractional_knapsack(vector<vector<int>>& v, int w) {
    sort(v.begin(), v.end(), [](auto& a, auto& b) {
        double x = double(a[0]) / a[1];
        double y = double(b[0]) / b[1];
        return x > y;
    });
    double ans = 0.0;
    for (auto& a : v) {
        if (w < a[1]) {
            ans += w * double(a[0]) / a[1];
            break;
        }  
        ans += a[0];
        w -= a[1];
    }
    return ans;
}