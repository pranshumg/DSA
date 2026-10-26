#include <bits/stdc++.h>

using namespace std;

/* Minimise maximum distance between gas stations */
// https://leetcode.com/problems/minimize-max-distance-to-gas-station/

// Greedy with Linear Scan
// TC - O(k * n), SC - O(n) 
long double minimise(vector<int>& v, int n, int k) {
    vector<int> placed(n - 1, 0);
    for (int gt = 0; gt < k; gt++) {
        long double mx = 0;
        int idx = -1;
        for (int i = 0; i < n - 1; i++) {
            long double dif = v[i + 1] - v[i];
            long double len = dif / (placed[i] + 1);
            if (len > mx) {
                mx = len;
                idx = i;
            }
        }
        placed[idx]++;
    }
    long double ans = 0;
    for (int i = 0; i < n - 1; i++) {
        long double dif = v[i + 1] - v[i];
        ans = max(ans, dif / (placed[i] + 1));
    }
    return ans;
}

// Greedy with Priority Queue (Heap)
// TC - O(k * log n), SC - O(n) 
long double minimise(vector<int>& v, int n, int k) {
    vector<int> placed(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++) {
        pq.emplace(v[i + 1] - v[i], i);
    }
    for (int gt = 0; gt < k; gt++) {
        auto tp = pq.top();
        pq.pop();
        int idx = tp.second;
        placed[idx]++;
        long double dif = v[idx + 1] - v[idx];
        long double len = dif / (placed[idx] + 1);
        pq.emplace(len, idx);
    }
    return pq.top().first;
}

// Binary Search on Answer
// TC: O(n * log(range/precision)), SC - O(1) 
long double minimise(vector<int>& v, int n, int k) {
    long double low = 0, high = 0;
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(v[i + 1] - v[i]));
    }
    while (high - low > 1e-6) {
        long double mid = low + (high - low) / 2.0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            int can_place = (v[i + 1] - v[i]) / mid;
            if (can_place * mid == v[i + 1] - v[i]) {
                can_place--;
            }
            cnt += can_place;
        }
        if (cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}