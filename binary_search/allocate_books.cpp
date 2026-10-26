#include <bits/stdc++.h>

using namespace std;

/* Allocate books */

int check(vector<int>& v, int mx) {
    int cnt = 1, sum = 0;
    for (int i : v) {
        if (sum + i <= mx) sum += i;
        else {
            sum = i;
            cnt++;
        }
    }
    return cnt;
}

// TC - O(n * (log(sum(v) - max(v)))), SC - O(1)
int allocate(vector<int>& v, int n, int m) {
    if (n < m) return -1;
    int low = 0, high = 0;
    for (int i : v) {
        low = max(low, i);
        high += i;
    }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(v, mid) <= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}